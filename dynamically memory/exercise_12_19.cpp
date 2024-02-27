#include <iostream>
#include "..\inc\StrBlobPtr.h"
using namespace std;

int main(int argc, char const *argv[])
{

    StrBlob b1;
    {
        StrBlob b2{"apple", "the", "water", "dog"};
        b1 = b2;
    }

    cout << b1.size() << endl;
    cout << b1.front() << " " << b1.back() << endl;
    b1.push_back("couple");
    cout << b1.back() << endl;
    

    const StrBlob b3 = b1;
    cout << b3.front() << " " << b3.back() << endl;

    for (StrBlobPtr iter = b1.begin(); neq(iter, b1.end()); iter.incre())
    {
        cout << iter.deref() << " ";
    }

    cout << endl;

    return 0;
}