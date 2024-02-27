#include <iostream>
#include <list>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include "../inc/Sales_data.h"
#include <iterator>
using namespace std;

int main(int argc, char const *argv[])
{
    ifstream read("D:/text.txt", ios::in);
    ofstream out1("D:/output_1.txt", ios::out), out2("D:/output_2.txt", ios::out);

    if (!read)
    {
        cerr << "file open error" << endl;
        return -1;
    }

    istream_iterator<int> in(read), eof;
    ostream_iterator<int> os1(out1, "\n"), os2(out2, "\n");

    while (in != eof)
    {
        if (*in % 2)
        {
            *os1++ = *in;
        }
        else
        {
            *os2++ = *in;
        }
        in++;
    }

    

    return 0;
}