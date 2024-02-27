#include <vector>
#include <string>
#include <iostream>
using namespace std;

string &replace_string(string &s, const string &oldVal, const string &newVal)
{
    for (auto beg = s.begin(); distance(beg, s.end()) > distance(oldVal.begin(), oldVal.end());)
    {
        if (string{beg, beg + oldVal.size()} == oldVal)
        {
            beg = s.erase(beg, beg + oldVal.size());
            beg = s.insert(beg, newVal.cbegin(), newVal.cend());
            beg += newVal.size();
        }
        else
        {
            beg++;
        }
    }
}

int main(int argc, char const *argv[])
{
    string s1{"aaathodddthothru"};

    replace_string(s1, "tho", "thought");
    cout << s1 << endl;

    return 0;
}