#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class StringGreater
{
private:
    size_t sz;

public:
    StringGreater(size_t n) : sz(n) {}
    bool operator()(const string &s)
    {
        return s.size() > sz;
    }
};

class StringBetween
{
private:
    size_t min, max;

public:
    StringBetween(size_t a, size_t b) : min(a), max(b) {}
    bool operator()(const string &s)
    {
        return s.size() > min && s.size() < max;
    }
};

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        cerr << "参数数量错误" << endl;
        return -1;
    }
    ifstream in(argv[1]);
    if (!in)
    {
        cerr << "读取文件失败" << endl;
        return -1;
    }

    string line, word;
    vector<string> svec;

    while (getline(in, line))
    {
        istringstream is(line);
        while (is >> word)
        {
            svec.push_back(word);
        }
    }

    cout << count_if(svec.cbegin(), svec.cend(), StringGreater(10)) << ends;
    putchar('\n');
    cout << count_if(svec.cbegin(), svec.cend(), StringBetween(1, 9)) << ends;

    return 0;
}