#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    cout << "ni hao," << flush;
    cout << "ni hao," << ends << "i love eating" << endl;

    ostream* old_tie = cin.tie(nullptr);
    int val;
    cout << "请输入一个整数:";
    cin >> val;

    return 0;
}