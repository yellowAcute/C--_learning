#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{

    int val = 43;
    string s = to_string(val);
    double d = stod(s);
    cout << val << endl;

    string s2 = "ddw=3.1234!!!!";
    d = stod(s2.substr(s2.find_first_of("-+.0123456789")));
    cout << d << endl;

    vector<char> vec{'a', 'c', 'w'};
    string s3(vec.begin(), vec.end());  
    




    return 0;
}