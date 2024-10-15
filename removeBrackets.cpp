#include <iostream>
#include <stack>
#include <string>

using namespace std;

string removeBrackets(string s) 
{
    stack<char> stack;
    string result = "";

    for (char c : s) 
    {
        if (c == '(') 
        {
            stack.push(c);
        } 
        else if (c == ')') 
        {
            while (stack.top() != '(') 
            {
                result += stack.top();
                stack.pop();
            }
            stack.pop(); // Remove the '('
        } 
        else 
        {
            if (!stack.empty() && stack.top() == '(') 
            {
                stack.push(c);
            } 
            else 
            {
                result += c;
            }
        }
    }

    while (!stack.empty()) 
    {
        result += stack.top();
        stack.pop();
    }

    string reversedResult = "";
    for (int i = result.size() - 1; i >= 0; i--) 
    {
        reversedResult += result[i];
    }

    return reversedResult;
}

int main() 
{
    string s;
    cout << "Enter a string: ";
    cin >> s;

    string result = removeBrackets(s);
    cout << "Result: " << result << endl;

    return 0;
}
