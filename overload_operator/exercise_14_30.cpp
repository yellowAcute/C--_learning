#include "../inc/StrBlobPtr.h"
using namespace std;

int main(int argc, char const *argv[])
{
    StrBlob str({"jack", "mike", "monkey", "elephant"});

    StrBlobPtr p(str, 2);
    cout << *p << endl;
    cout << *++p << endl;
    cout << p[0] << endl;
    

    return 0;
}