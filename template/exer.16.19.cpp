#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void print(const T &vec)
{
    for (typename T::size_type i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << ends;
    }

    for (typename T::const_iterator iter = begin(vec); iter != end(vec); iter++)
    {
        cout << *iter << ends;
    }
}

int main(int argc, char const *argv[])
{
    print(vector<int>{12, 12, 3, 4, 5, 5});

    return 0;
}