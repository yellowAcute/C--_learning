#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << "int 9/5 = " << 9 / 5 << endl;
    cout << "float 9.0/5 = " << 9.0 / 5 << endl;
    cout << "float size:" << sizeof(float) << endl;
    // cout << "int 9/5 = " << 9 / 5 <`< endl;
    cout << "int  size:" << sizeof(int) << endl;

    return 0;
}