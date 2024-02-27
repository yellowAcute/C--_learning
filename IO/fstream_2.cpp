#include <vector>
#include <fstream>
#include <iostream>
#include "../inc/Sales_data.h"
using namespace std;

int main(int argc, char const *argv[])
{

    fstream in(argv[1], ios::in);
    if (!in)
    {
        cerr << "file open error" << endl;
        return -1;
    }

    Sales_data total;
    if (read(in, total))
    {
        Sales_data trans;
        while (read(in, trans))
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