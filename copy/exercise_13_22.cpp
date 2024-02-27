#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class HasPtr
{
    friend void swap(HasPtr &, HasPtr &);

private:
    string *ps;
    int i;

public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &p) : ps(new string(*p.ps)), i(p.i) {}

    HasPtr &operator=(const HasPtr &rth)
    {
        string *newps = new string(*rth.ps);
        //  释放掉原对象中的字符串指针指向的对象
        delete ps;
        ps = newps;
        i = rth.i;
        return *this;
    }
    HasPtr &operator=(const string &s)
    {
        *ps = s;
        return *this;
    }

    bool operator<(const HasPtr &rhs)
    {
        return *ps < *rhs.ps;
    }

    string &operator*()
    {
        return *ps;
    }

    ~HasPtr();
};

HasPtr::~HasPtr()
{
    delete ps;
}

void swap(HasPtr &lhs, HasPtr &rhs)
{
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    cout << "交换" << *lhs.ps << ends << *rhs.ps << endl;
}

int main(int argc, char const *argv[])
{
    HasPtr a("jie jie");
    HasPtr b("jack");
    HasPtr c(b);
    HasPtr d("tom");
    HasPtr e("alibaba");
    a = "maka baka";

    cout << *a << endl;
    cout << *b << endl;
    cout << *c << endl;
    cout << *d << endl;

    cout << endl;

    vector<HasPtr> vec{a, b, c, e};
    sort(vec.begin(), vec.end());

    for (auto &&i : vec)
    {
        cout << *i << endl;
    }

    return 0;
}