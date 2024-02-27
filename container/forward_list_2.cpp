#include <iostream>
#include <forward_list>
using namespace std;

int main(int argc, char const *argv[])
{
    forward_list<int> lst{12, 34, 56, 32, 23, 45, 56, 75};
    auto prev = lst.before_begin();

    for (auto i = lst.begin(); i != lst.end();)
    {
        if (*i % 2)
        {
            i = lst.insert_after(i, *i);
            prev = i;
            i++;
        }
        else
        {
            i = lst.erase_after(prev);
        }
    }

    for (auto &&i : lst)
    {
        cout << i << ends;
    }

    return 0;
}