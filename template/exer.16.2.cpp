#include "../inc/Template.h"

int main(int argc, char const *argv[])
{
    cout << compare(1, 2) << endl;

    vector<int> vec{12, 4, 2, 32, 45, 30};
    auto result = find(vec.cbegin(), vec.cend(), 2);
    cout << *result << endl;

    int arr[]{22, 3, 2, 4, 5, 322, 445, 112, 344};
    print(arr);

    cout << size(arr) << endl;

    return 0;
}