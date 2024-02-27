#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <utility>
#include <list>
using namespace std;

int main(int argc, char const *argv[])
{

    vector<pair<string, int>> vec;
    string s;
    int i;
    while (cin >> s && cin >> i)
    {
        vec.push_back(make_pair(s, i));
    }

    for_each(vec.cbegin(), vec.cend(), [](const pair<string, int> &p)
             { cout << p.first << ends << p.second << endl; });

    return 0;
}