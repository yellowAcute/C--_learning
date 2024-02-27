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
    vector<int> vec{11, 12, 123, 44, 54, 13, 34};
    list<int> lst;

    sort(vec.begin(), vec.end());

    unique_copy(vec.begin(), vec.end(), back_inserter(lst));

    ostream_iterator<int> out_iter(cout, " ");

    for (auto &&i : lst)
    {
        *out_iter++ = i;
    }
    return 0;
}