#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <utility>
#include "../inc/Sales_data.h"
using namespace std;

int main(int argc, char const *argv[])
{

    multimap<string, string> authors{
        {"Smith", "www"}, {"Dan", "aaa"}, {"Jane", "ddd"}, {"Smith", "tea"}};

    string name;
    multimap<string, string>::iterator it;

    while (cin >> name)
    {
        it = authors.find(name);
        
        if (it != authors.end())
        {
            authors.erase(it);
        }
    }

    for (auto beg = authors.begin(); beg != authors.end(); )
    {
        cout << beg->first << ends;
        auto i = authors.equal_range(beg->first);
        for (; i.first != i.second; ++i.first)
        {

            cout << i.first->second << ends;
        }
        cout << endl;
        beg = i.second;
    }

    return 0;
}