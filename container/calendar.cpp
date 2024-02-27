#include <iostream>
#include "../inc/Calendar.h"
using namespace std;

int main(int argc, char const *argv[])
{
    Calendar date{"Feb 2,2001"};
    date.print();

    return 0;
}