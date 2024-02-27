#include <iostream>
#include <vector>
using namespace std;

void toLower(string &s)
{

    for (auto &&i : s)
    {
        if (isupper(i))
        {
            i = tolower(i);
        }
    }
}

void getSum(initializer_list<int> list)
{
    int sum = 0;
    for (decltype(list.begin()) i = list.begin(); i != list.end(); i++)
    {
        sum += *i;
    }

    cout << sum << endl;
}

int func5(int);

int add(int, int);
int subtract(int, int);
int multiply(int, int);
int divide(int, int);

int main(int argc, char const *argv[])
{
    string s("aaaDDSDfxfgDG");
    toLower(s);
    cout << s << endl;

    string(&func1())[10];

    using arrType = string[10];
    arrType *func2();

    auto func3(int i)->string(*)[10];

    string s[10];
    decltype(s) *func4(int i);

    int (*p1)(int, int) = add;
    int (*p2)(int, int) = subtract;
    int (*p3)(int, int) = multiply;
    int (*p4)(int, int) = divide;
    vector<int (*)(int, int)>{p1, p2, p3, p4};

    getSum({1, 23, 4, 56, 7});

    return 0;
}