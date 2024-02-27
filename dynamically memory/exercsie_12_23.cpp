#include <iostream>
#include <cstring>
#include <memory>
using namespace std;

int main(int argc, char const *argv[])
{

    char *ch = new char[100]();
    const char *c1 = "apple monkey";
    const char *c2 = "bear mouse";
    strcpy(ch, c1);
    strcat(ch, c2);
    cout << ch << endl;

    string s1 = "hello ";
    string s2 = "world";
    strcpy(ch, (s1 + s2).c_str());
    cout << ch << endl;
    delete[] ch;



    int size{0};
    cin >> size;
    cin.ignore(); // 忽略输入长度为size末尾输入的字符，如空格或换行
    char *r = new char[size + 1]();
    cout << "输入字符串：";
    cin.get(r, size);  // 向数组r中输入size个字符

    cout << r << endl;
    delete[] r;

    return 0;
}