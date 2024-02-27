#include "../inc/Screen.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    Screen myscreen(5, 5, 'x');
    myscreen.move(4, 0).set('&').display(cout);
    cout << "\n";
    myscreen.display(cout);
    cout << "\n";

    return 0;
}