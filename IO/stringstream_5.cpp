#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

struct PeopleInfo
{
    string name;
    vector<string> phone;
};

int main(int argc, char const *argv[])
{
    string line, word;
    vector<PeopleInfo> pepole;
    PeopleInfo info;

    ifstream ifs("D:/people.txt");
    if (!ifs.is_open())
    {
        cerr << "file open error" << endl;
        return -1;
    }

    istringstream is;
    while (getline(ifs, line))
    {
        is.str(line);
        is >> info.name;
        while (is >> word)
        {
            info.phone.push_back(word);
        }
        pepole.push_back(info);
    }
    
    



    return 0;
}