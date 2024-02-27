#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{

    ifstream read("D:/text.txt", ios::in);

    string s;
    vector<string> vec;

    if (!read)
    {
        cerr << "file open error" << endl;
        return -1;
    }

    while (getline(read, s))
    {

        vec.push_back(s);
    }

    for (auto &&i : vec)
    {
        cout << i << endl;
    }

    return 0;
}