#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> s{"12", "23", "22", "10"};
    int sum = 0;
    for (auto &&i : s)
    {
        sum += stoi(i);
    }
    cout << sum << endl;

    return 0;
}