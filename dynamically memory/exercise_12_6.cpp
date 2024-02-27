#include <iostream>
#include <memory>
#include <new>
#include <vector>
using namespace std;

shared_ptr<vector<int>> Factory()
{
    return make_shared<vector<int>>();
}

shared_ptr<vector<int>> write_vector()
{
    int a;
    shared_ptr<vector<int>> vec = Factory();
    while (cin >> a)
    {
        vec->push_back(a);
    }

    return vec;
}

void displayVector()
{
    shared_ptr<vector<int>> vec(write_vector());
    if (!vec)
    {
        cerr << "memory out" << endl;
        return;
    }

    auto beg = vec->begin();

    while (beg != vec->end())
    {
        cout << *beg << ends;
        beg++;
    }
}

int main(int argc, char const *argv[])
{
    displayVector();

    return 0;
}