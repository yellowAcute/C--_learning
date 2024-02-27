#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

istream &read(istream &in)
{
    string s;
    while (getline(in, s))
    {
        cout << s << endl;
    }

    in.clear();
    return in;
}

int main(int argc, char const *argv[])
{
    istringstream is("wwwdddd");
    read(is);
    


    return 0;
}