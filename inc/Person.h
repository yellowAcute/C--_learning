#if !defined(PERSON_H)
#define PERSON_H
#include <string>
#include <iostream>
using namespace std;

class Person
{
    friend ostream &print(ostream &, const Person &);
    friend istream &read(istream &, Person &);

private:
    string Name;
    string Address;

public:
    Person::Person(const string& name, const string& address);
    ~Person();
    string getName() const { return Name; }
    string getAddress() const { return Address; }
};

Person::Person(const string& name, const string& address):Name(name)
            , Address(address) { }

Person::~Person()
{
}

ostream &print(ostream &os, const Person &p)
{
    os << p.getName() << " "
       << p.getAddress();
    return os;
}

istream &read(istream &is, Person &p)
{
    is >> p.Name >> p.Address;
    return is;
}

#endif // PERSON_H
