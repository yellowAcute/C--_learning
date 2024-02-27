#if !defined(TEMPLATE_H)
#define TEMPLATE_H

using namespace std;
#include <iostream>
#include <vector>

template <typename T>
int compare(const T &lhs, const T &rhs)
{
    if (less<T>()(lhs, rhs))
    {
        return 1;
    }
    if (less<T>()(rhs, lhs))
    {
        return -1;
    }
    return 0;
}

template <typename T, typename U>
T find(T b, T e, const U &val)
{
    while (b != e)
    {
        if (*b == val)
        {
            return b;
        }
        b++;
    }

    return b;
}

template <typename T, unsigned N>
void print(const T (&arr)[N])
{
    for (auto &&i : arr)
    {
        cout << i << ends;
    }
    cout << endl;
}

template <typename T, size_t N>
const T *begin(const T (&arr)[N])
{
    return arr;
}

template <typename T, size_t N>
const T *end(const T (&arr)[N])
{
    return arr + N;
}

template <typename T, size_t N>
constexpr size_t size(const T (&arr)[N])
{
    return end(arr) - begin(arr);
}



#endif // TEMPLATE_H
