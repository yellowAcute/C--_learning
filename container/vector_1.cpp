#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vec;

    cout << "vec size:" << vec.size() << ends << "vec capacity:" << vec.capacity() << endl;

    for (vector<int>::size_type i = 0; i != 10; i++)
    {
        vec.push_back(i);
    }

    cout << "vec size:" << vec.size() << ends << "vec capacity:" << vec.capacity() << endl;
    
    vec.reserve(20);
    cout << "vec size:" << vec.size() << ends << "vec capacity:" << vec.capacity() << endl;
    

    return 0;
}