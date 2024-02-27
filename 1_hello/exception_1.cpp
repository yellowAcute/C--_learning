#include <stdexcept>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int val1, val2;
    while (cin >> val1 >> val2)
    {
        try
        {
            if (val2 == 0)
            {
                throw runtime_error("除数不能为0");
            }
        }
        catch (const std::runtime_error &e)
        {
            std::cerr << e.what() << '\n'
                      << "Try again? Entry y or n" << endl;
            char c;
            cin >> c;
            if (c == 'n' || !cin)
            {
                break;
            }
        }
    }

    return 0;
}