#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vec{1, 23, 43, 45, 5, 2, 11, 22};
    list<int> lst1, lst2, lst3;

    copy(vec.begin(), vec.end(), back_inserter(lst1));
    for (auto &&i : lst1)
    {
        cout << i << ends;
    }
    cout << endl;

    copy(vec.begin(), vec.end(), front_inserter(lst2));
    for (auto &&i : lst2)
    {
        cout << i << ends;
    }
    cout << endl;

    copy(vec.begin(), vec.end(), inserter(lst3, lst3.begin()));
    for (auto &&i : lst3)
    {
        cout << i << ends;
    }
    cout << endl;

    return 0;
}