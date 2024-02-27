#include <vector>
#include <string>
#include <iostream>
using namespace std;

string &replace_string(string &s, const string &oldVal, const string &newVal)
{
    string::size_type i = 0;

    while ((i = s.find(oldVal, i)) != string::npos)
    {
        s.replace(i, oldVal.size(), newVal);
        i += newVal.size();
        

    }
}

int main(int argc, char const *argv[])
{
    string s1{"aaathodddthothru"};

    replace_string(s1, "tho", "thought");
    cout << s1 << endl;

    return 0;
}