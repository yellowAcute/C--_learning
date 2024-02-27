#if !defined(EMPLOYEE_H)
#define EMPLOYEE_H
#include <iostream>
#include <string>
using namespace std;

class Employee
{

private:
    string name;
    static int seq;
    // int seq = 0;
    int id;

public:
    Employee() : id(seq++) {}
    Employee(const string &s) : name(s), id(seq++) {}
    
    Employee(const Employee &e) : name(e.name), id(seq++) {}
    Employee &operator=(const Employee &e)
    {
        name = e.name;
        return *this;
    }

    ~Employee() = default;

    const string &getName()
    {
        return this->name;
    }
    int getId()
    {
        return this->id;
    }
};

void f(Employee &e)
{
    cout << e.getName() << ends << e.getId() << endl;
}

#endif // EMPLOYEE_H
