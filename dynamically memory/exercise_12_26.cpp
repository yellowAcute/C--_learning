#include <iostream>
#include <memory>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{

    allocator<string> alloc;

    string *const p = alloc.allocate(100);
    string s;
    string *q = p;
    while (cin >> s && q != p + 10)
    {
        alloc.construct(q++, s);
    }
    const int size = q - p;

    for (size_t i = 0; i < size; i++)
    {
        cout << p[i] << endl;
    }

    while (q != p)
    {
        alloc.destroy(--q);
    }

    return 0;
}