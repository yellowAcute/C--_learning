#include <numeric>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{

    vector<string> svec{"aaa", "ddwd", "www"};

    string str = accumulate(svec.cbegin(), svec.cend(), string{"qqqq"});
    cout << str << endl;

    vector<double> dvec{1.1, 12.3, 13.2, 34.1};
    cout << accumulate(dvec.cbegin(), dvec.cend(), 0) << endl;

    return 0;
}