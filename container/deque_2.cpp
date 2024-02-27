#include <deque>
#include <iostream>
#include <list>
using namespace std;

int main(int argc, char const *argv[])
{
    deque<int> dq_odd, dq_even;
    list<int> lst{1, 23, 4, 55, 6, 778, 34, 2, 33, 45, 62, 12, 2, 4, 67, 78};
    int a;

    for (list<int>::iterator i = lst.begin(); i != lst.end(); i++)
    {
        if (*i % 2)
        {
            dq_odd.push_back(*i);
        }
        else
        {
            dq_even.push_back(*i);
        }
    }

    for (auto &&i : dq_odd)
    {
        cout << i << ends;
    }
    cout << endl;
    for (auto &&i : dq_even)
    {
        cout << i << ends;
    }

    return 0;
}