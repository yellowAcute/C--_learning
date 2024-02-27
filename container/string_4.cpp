#include <vector>
#include <string>
#include <iostream>
using namespace std;

string &updateName(string &name, const string &up, const string &back)
{
    name.insert(0, up);
    name.insert(name.size(), back);
    return name;
}

int main(int argc, char const *argv[])
{
    string Name{"HuangAcute"}, up{"Mr."}, back{"III"};

    Name = updateName(Name, up, back);
    cout << Name << endl;

    return 0;
}