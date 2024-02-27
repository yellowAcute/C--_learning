#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> vec{"wordsaaaa", "redwwww", "wwwdddd", "red", "tea", "word", "over", "apple"};
    string::size_type sz = 6;

    auto a = count_if(vec.cbegin(), vec.cend(), [sz](const string &s)
                      { return s.size() > 6; });

    cout << a << endl;

    int x = 10;
    auto f = [x]() mutable -> bool
    {
        if (!x)
            return true;
        else
        {
            x--;
            return false;
        }
    };

    return 0;
}