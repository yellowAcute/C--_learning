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
 
public:
    typedef std::vector<std::string>::size_type size_type;

    // constructors
    StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
    StrBlob(std::initializer_list<std::string> il);

    StrBlob(const StrBlob &rth) : data(make_shared<vector<string>>(*rth.data))
    {
    }

    StrBlob &operator=(const StrBlob &rth)
    {
        data = make_shared<vector<string>>(*rth.data);
        return *this;
    }

    // size operations
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    // add and remove elements
    void push_back(const std::string &t) { data->push_back(t); }
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

    // 打印出所有元素
};

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
