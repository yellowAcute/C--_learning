#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    ifstream ifs("D:/book.txt");
    if (!ifs.is_open())
    {
        cerr << "file open error" << endl;
        return -1;
    }

    vector<string> vec;
    string s;
    while (getline(ifs, s))
    {
        vec.push_back(s);
    }

    string word;
    for (auto &&i : vec)
    {
        istringstream is(i);
        while (is >> word)
        {
            cout << word << ends;
        }
        cout << endl;
    }

    return 0;
}