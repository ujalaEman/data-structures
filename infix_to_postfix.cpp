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

string infixToPostfix(string infix)
{
    stack<char> s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        if (isAlphaNumeric(c))
        {
            postfix += c;
        }
        else if (c == '(') 
        {
            s.push('(');
        }
        else if (c == ')') 
        {
            while (s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.empty() && precedence(c) <= precedence(s.top()))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}



int main()
{
    string infix = "A+B*C-D";
    cout << "Infix Expression: " << infix << endl;
    cout << "Postfix Expression: " << infixToPostfix(infix) << endl;
    return 0;
}
