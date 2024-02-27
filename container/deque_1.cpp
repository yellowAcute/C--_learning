#include <deque>
#include <iostream>
#include <list>
using   namespace std;



int main(int argc, char const *argv[])
{
    string s;
    list<string> dq;
    while (cin >> s)
    {
        dq.push_back(s);
    }
    
    for (list<string>::iterator i = dq.begin(); i != dq.end(); i++)
    {
        cout << *i << endl;
    }
    
    
    



    return 0;
}