#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    auto sum = [](int a, int b)
    { return a + b; };

    cout << sum(1, 2) << endl;

    int a = 0;
    auto sum1 = [a](int b)
    { return a + b; };
    cout << sum1(2) << endl;

    

    return 0;
}