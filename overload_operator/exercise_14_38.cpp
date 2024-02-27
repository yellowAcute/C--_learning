#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class StringCom
{
private:
    size_t sz;

public:
    StringCom(size_t n) : sz(n) {}
    bool operator()(const string &s)
    {
        return s.size() == sz;
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

    for (size_t i = 1; i < 11; i++)
    {
        cout << count_if(svec.cbegin(), svec.cend(), StringCom(i)) << endl;
        
    }

    return 0;
}