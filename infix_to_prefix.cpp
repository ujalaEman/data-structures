#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

bool isAlphaNumeric(char ch)
{
    if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        return true;
    return false;
}

string infixToPrefix(string infix)
{
    stack<string> s;
    string prefix = "";

    for (int i = infix.length() - 1; i >= 0; i--)
    {
        char c = infix[i];

        if (isAlphaNumeric(c))
        {
            prefix = c + prefix;
        }
        else if (c == ')')
        {
            s.push(string(1, c));
        }
        else if (c == '(')
        {
            while (!s.empty() && s.top() != ")")
            {
                prefix = s.top() + prefix;
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.empty() && precedence(c) < precedence(s.top()[0]))
            {
                prefix = s.top() + prefix;
                s.pop();
            }
            s.push(string(1, c));
        }
    }

    while (!s.empty())
    {
        prefix = s.top() + prefix;
        s.pop();
    }

    return prefix;
}

int main()
{
    string infix = "A+B*C-D";
    cout << "Infix Expression: " << infix << endl;
    cout << "Prefix Expression: " << infixToPrefix(infix) << endl;
    return 0;
}
