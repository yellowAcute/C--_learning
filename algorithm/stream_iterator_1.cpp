#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> svec;

    ifstream read("D:/book.txt", ios::in);
    if (!read)
    {
        cerr << "file open error" << endl;
        return -1;
    }

    istream_iterator<string> in_iter(read), eof;
    while (in_iter != eof)
    {
        svec.push_back(*in_iter++);
    }

    for (auto &&i : svec)
    {
        cout << i << ends;
    }
    


    return 0;
}