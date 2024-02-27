#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int main(int argc, char const *argv[])
{
    map<string, vector<pair<string, string>>> home = {{"��", {{"����", "1999-9-1"}, {"�¹�", "1992-1-2"}}},
                                                      {"��", {{"����", "1999-1-3"}, {"��", "2001-1-3"}}}};

    vector<pair<string, string>> birthday;

    string name;
    string day;
    while (cin >> name && cin >> day)
    {
        string first_name = name.substr(0, 1);
        if (home.find(first_name) == home.end())
        {
            home[first_name].push_back(make_pair(name.substr(1), day));
        }
        else
        {
            home[first_name].push_back(make_pair(name.substr(1), day));
        }
    }

    for (const auto &i : home)
    {
        for (const auto &j : i.second)
        {
            cout << i.first << j.first << " " << j.second;
        }
        cout << endl;
    }

    return 0;
}