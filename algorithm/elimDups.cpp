#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> vec{"word", "red", "www", "red", "tea", "word", "over", "apple"};

    sort(vec.begin(), vec.end());
    auto end_unique = unique(vec.begin(), vec.end());

    vec.erase(end_unique, vec.cend());

    for (auto &&i : vec)
    {
        cout << i << ends;
    }

    return 0;
}