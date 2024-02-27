#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../inc/Sales_data.h"
using namespace std;

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

int main(int argc, char const *argv[])
{

    vector<string> vec{"word", "red", "www", "red", "tea", "word", "over", "apple"};

    stable_sort(vec.begin(), vec.end(), isShorter);

    for (auto &&i : vec)
    {
        cout << i << ends;
    }
    cout << endl;

    vector<Sales_data> sales_vec{Sales_data("0001"), Sales_data("0001"), Sales_data("0010")};
    stable_sort(sales_vec.begin(), sales_vec.end(), [](Sales_data s1, Sales_data s2)
                { return s1.isbn() == s2.isbn(); });

    for (auto &&s : sales_vec)
    {
        // print(cout, s);
        cout << s << ends;
    }

    return 0;
}