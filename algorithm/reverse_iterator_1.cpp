#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main(int argc, char const *argv[])
{

    list<int> lst{12, 32, 33, 34, 45, 55, 0, 22, 0, 32};

    vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> lst1;

    auto zero = find(lst.crbegin(), lst.crend(), 0);

    copy(vec.crbegin() + 2, vec.crend() - 3, back_inserter(lst1));

    for_each(lst1.cbegin(), lst1.cend(), [](const int &a)
             { cout << a << ends; });



    return 0;



}