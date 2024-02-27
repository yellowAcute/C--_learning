#include <iostream>
#include <forward_list>
using namespace std;

void insert_forward_list(forward_list<string> &lst, const string &s1, const string &s2)
{
    auto i = lst.begin();
    forward_list<string>::iterator prev = i;
    for (; i != lst.end(); i++)
    {
        if (*i == s1)
        {
            lst.insert_after(i, s2);
            return;
        }
        prev = i;
    }
    lst.insert_after(prev, s2);
}

int main(int argc, char const *argv[])
{
    forward_list<string> slst{"wwww", "dd"};
    string s1{"aaa"}, s2{"ccc"};
    insert_forward_list(slst, s1, s2);
    for (auto &&i : slst)
    {
        cout << i << ends;
    }

    insert_forward_list(slst, s1, s2);

    forward_list<int> lst{12, 1, 223, 43, 11, 33, 43, 54, 32, 13, 45, 6};
    forward_list<int>::iterator prev = lst.before_begin();
    forward_list<int>::iterator curr = lst.begin();

    while (curr != lst.end())
    {
        if (*curr % 2)
        {
            curr = lst.erase_after(prev);
        }
        else
        {
            prev = curr;
            curr++;
        }
    }

    return 0;
}