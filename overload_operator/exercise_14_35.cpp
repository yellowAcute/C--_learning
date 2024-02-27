#include "../inc/StrBlobPtr.h"
#include <algorithm>
using namespace std;

class PrintString
{
private:
    istream &is;
    char sep;
    string line;

public:
    vector<string> svec;

    PrintString(istream &);
    // string operator()();
    void operator()();
};

// string PrintString::operator()()
// {
//     string line;
//     if (getline(is, line))
//     {
//         return line;
//     }
//     return 0;
// }

void PrintString::operator()()
{
    while (getline(is, line))
    {
        svec.push_back(line);
    }
}

PrintString::PrintString(istream &i = cin) : is(i)
{
}

int main(int argc, char const *argv[])
{
    PrintString read;
    // cout << read();
    read();

    for_each(read.svec.cbegin(), read.svec.cend(), [](const string &s)
             { cout << s << ends; }); 

    return 0;
}