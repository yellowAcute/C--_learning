#include <iostream>
#include <list>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> vec{"word", "www", "red", "www", "red", "tea", "red", "word", "over", "apple"};

    list<string> lst;

    sort(vec.begin(), vec.end());
    copy(vec.cbegin(), vec.cend(), back_inserter(lst));

    lst.unique();

    for_each(lst.cbegin(), lst.cend(), [](const string &s)
             { cout << s << ends; });

             

    return 0;
}