#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> vec{"word", "www", "red", "www", "red", "tea", "red", "word", "over", "apple"};

    list<string> lst;
    sort(vec.begin(), vec.end());
    unique_copy(vec.begin(), vec.end(), back_inserter(lst));

    for (auto &&i : lst)
    {
        cout << i << ends;
    }

    return 0;
}