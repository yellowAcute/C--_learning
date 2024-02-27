#include <stack>
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    string str = "This is (Mooophy(awesome)((((wooooooooo))))) and (ocxs) over";

    int seen = 0;
    stack<char> stk;
    char repl = '#';

    for (string::size_type i = 0; i < str.size(); i++)
    {
        stk.push(str[i]);
        if (str[i] == '(')
        {
            seen++;
        }
        if (seen && str[i] == ')')
        {
            while (stk.top() != '(')
            {
                stk.pop();
            }
            stk.pop();
            stk.push(repl);

            --seen;
        }
    }

    string s;
    while (!stk.empty())
    {
        s.insert(s.begin(), stk.top());
        stk.pop();
    }

    return 0;
}