#include <iostream>
#include "../inc/Sales_data.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Sales_data total;
    if (cin >> total)
    {
        Sales_data trans;
        while (cin >> trans)
        {
            if (trans.isbn() == total.isbn())
            {
                total.combine(trans);
            }
            else
            {
                cout << total << endl;
                total = trans;
            }
        }
        cout << total << endl;
    }

    return 0;
}