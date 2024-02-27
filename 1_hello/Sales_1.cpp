#include <iostream>
#include "../inc/Sales_item.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Sales_item total, trans;

    if (cin >> trans)
    {
        total = trans;
        while (cin >> trans)
        {
            if (trans.isbn() == total.isbn())
            {
                total += trans;
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