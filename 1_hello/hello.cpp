#include <climits>
#include <iostream>
using   namespace std;



int main(int argc, char const *argv[])
{
    cout << "int :"<< sizeof(int)<<endl;
    cout << "short :"<< sizeof(short)<<endl;
    cout << "long :"<< sizeof(long)<<endl;
    cout << "long long:"<< sizeof(long long)<<endl;

    cout << "int MAX:" << INT_MAX<<endl;
    cout << "char MAX:" << CHAR_MAX<<endl;
    cout << "char bit:" << CHAR_BIT<<endl;
    cout << "int MIN:" << INT_MIN<<endl;

    wchar_t ch = L'P' ;
    //  wchar_t : 4B
    cout << "wchar_t:"<<sizeof ch <<endl;
    cout << "char:" << sizeof (char) <<endl;
    //  wcout: 输出的字符为wchar_t类型
    wcout << L"123"<<endl;
    cout << sizeof L"123" << endl;

    return 0;
}