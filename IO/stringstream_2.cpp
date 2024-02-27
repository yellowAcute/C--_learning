#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

istream &read(istream &in)
{
    string s;
    while (getline(cin, s))
    {
        cout << s << endl;
    }

    in.clear();
    return in;
}

int main(int argc, char const *argv[])
{
    read(cin);
    


    return 0;
}