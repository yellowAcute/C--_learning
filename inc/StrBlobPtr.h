#if !defined(STRBLODPTR_H)
#define STRBLODPTR_H
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include <new>
using namespace std;

// forward declaration needed for friend declaration in StrBlob
class StrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;
    friend bool operator==(const StrBlob &, const StrBlob &);
    friend bool operator!=(const StrBlob &, const StrBlob &);

public:
    typedef std::vector<std::string>::size_type size_type;

    // constructors
    StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
    StrBlob(std::initializer_list<std::string> il);

    // size operations
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    // add and remove elements
    void push_back(const std::string &t) { data->push_back(t); }
    void push_back(string &&t)
    {
        data->push_back(move(t));
    }

    void pop_back();

    // element access
    std::string &front();
    const string &front() const;
    std::string &back();
    const string &back() const;

    // interface to StrBlobPtr
    StrBlobPtr begin(); // can't be defined until StrBlobPtr is
    StrBlobPtr end();

private:
    std::shared_ptr<std::vector<std::string>> data;
    // throws msg if data[i] isn't valid
    void check(size_type i, const std::string &msg) const
    {
        if (i >= data->size())
        {
            throw out_of_range(msg);
        }
    }
    bool eq(const StrBlob &, const StrBlob &);
};

StrBlob::StrBlob(std::initializer_list<std::string> il) : data(std::make_shared<std::vector<std::string>>(il)) {}

bool operator==(const StrBlob &lht, const StrBlob &rhs)
{
    return lht.data == rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs.data == rhs.data);
}

string &StrBlob::front()
{
    check(0, "front on empty strBlob");
    return data->front();
}

const string &StrBlob::front() const
{
    check(0, "front on empty strBlob");
    return data->front();
}

string &StrBlob::back()
{
    check(0, "back on empty strBlob");
    return data->back();
}

const string &StrBlob::back() const
{
    check(0, "back on empty strBlob");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "back on empty strBlob");
    data->pop_back();
}

class StrBlobPtr
{
    friend bool eq(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
    friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);

private:
    size_t curr;
    // 检查此时指向字符串的指针所处的位置是否合法，msg为报错信息
    shared_ptr<vector<string>> check(size_t, const string &) const;
    weak_ptr<vector<string>> wptr;

public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    string &deref() const;
    StrBlobPtr &incre();
    StrBlobPtr &decre();

    string &operator*() const;
    string *operator->() const;
    StrBlobPtr &operator++();
    StrBlobPtr &operator--();
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);
    string &operator[](size_t);

    // 打印出所有元素
};

string &StrBlobPtr::operator[](size_t n) 
{
    auto p = check(n, "dereference error");
    return (*p)[n];
    
}

StrBlobPtr &StrBlobPtr::operator++()
{
    check(curr, "increment past end of strblobptr");
    curr++;
    return *this;
}

StrBlobPtr &StrBlobPtr::operator--()
{
    curr--;
    check(curr, "increment past end of strblobptr");
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int)
{
    StrBlobPtr ret = *this;
    ++*this;
    return ret;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr ret = *this;
    --*this;
    return ret;
}

string &StrBlobPtr::operator*() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

string *StrBlobPtr::operator->() const
{
    return &this->operator*();
}

shared_ptr<vector<string>> StrBlobPtr::check(size_t z, const string &msg) const
{

    auto ref = wptr.lock();
    if (!ref)
    {
        throw runtime_error("unbound StrBlobPtr");
    }
    if (z >= ref->size())
    {
        throw out_of_range(msg);
    }
    return ref;
}

string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incre()
{
    check(curr, "increment past end of strblobptr");
    curr++;
    return *this;
}

StrBlobPtr &StrBlobPtr::decre()
{
    curr--;
    check(curr, "decrement past begin of StrBlobPtr");
    return *this;
}

bool eq(const StrBlobPtr &lth, const StrBlobPtr &rth)
{
    auto l = lth.wptr.lock(), r = rth.wptr.lock();
    if (l == r)
    {
        return (!r || lth.curr == rth.curr);
    }
    return false;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    if (l == r)
    {
        //  当两指针为空或指针指向相同元素时，两指针相等
        return (!r || lhs.curr == rhs.curr);
    }
    return false;
}

bool neq(const StrBlobPtr &lth, const StrBlobPtr &rth)
{
    return !eq(lth, rth);
}

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
    auto ref = StrBlobPtr(*this, data->size());
    return ref;
}

#endif // STRBLODPTR_H
