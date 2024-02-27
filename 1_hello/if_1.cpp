#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{

    int val = 0, count = 0, saveVal = 0;
    if (cin >> val)
    {
        count++;
        saveVal = val;
        while (cin >> val)
        {
            if (val == saveVal)
            {
                count++;
            }
            else
            {
                cout << saveVal << "\toccur\t" << count << "\ttime" << endl;
                count = 1;
                saveVal = val;
            }
        }
        cout << saveVal << "occur" << count << "time" << endl;
    }

    return 0;
}