#include "../inc/Employee.h"

// 类中声明的static成员， 必须要给其赋值
int Employee::seq = 0;

int main(int argc, char const *argv[])
{
    Employee a("mike"), b("lucy"), c;
    c = b;

    f(a);
    f(b);
    f(c);

    return 0;
}