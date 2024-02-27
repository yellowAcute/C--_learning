#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <utility>
#include "../inc/Sales_data.h"
using namespace std;

int main(int argc, char const *argv[])
{

    multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)> bookstore(compareIsbn);

    multiset<Sales_data, bool (*)(const Sales_data &, const Sales_data &)>::iterator it = bookstore.begin();

    map<string, vector<int>> c;
    map<string, vector<int>>::iterator it = c.find(string("aaa"));

    
    



    return 0;
}