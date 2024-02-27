#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    string s{"ab2c3d7R4E6"};
    string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string number{"0123456789"};

    string::size_type i = 0, pos = 0;
    while ((i = s.find_first_of(number, i)) != string::npos)
    {
        cout << i << ends;
        i++;
    }
    cout << endl;

    i = 0;
    while ((i = s.find_first_of(alphabet, i)) != string::npos)
    {
        cout << i << ends;
        i++;
    }

    cout << endl; 
    i = 0;
    while ((i = s.find_first_not_of(alphabet, i)) != string::npos)
    {
        cout << i << ends;
        i++;
    }

    return 0;
}