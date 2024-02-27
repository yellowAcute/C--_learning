#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

struct PersonInfo
{
    string name;
    vector<string> phone;
};

int main(int argc, char const *argv[])
{
    string line, word;
    vector<PersonInfo> person;

    while (cin >> line)
    {
        PersonInfo people;
        istringstream record(line);
        record >> people.name;
        while (record >> word)
        {
            people.phone.push_back(word);
        }
        person.push_back(people);
    }

    

    return 0;
}