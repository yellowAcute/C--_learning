#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

string &tran(string &s)
{
    for (size_t i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += ('a' - 'A');
        }
        else if (s[i] == ',' || s[i] == '.')
        {
            s.erase(i);
        }
    }

    return s;
}

int main(int argc, char const *argv[])
{

    map<string, size_t> word_count;

    string s;
    while (cin >> s)
    {
        ++word_count[tran(s)];
    }

    map<string, size_t>::const_iterator it = word_count.cbegin();
    while (it != word_count.cend())
    {
        cout << it->first << ends << it->second << endl;
    }

    return 0;
}