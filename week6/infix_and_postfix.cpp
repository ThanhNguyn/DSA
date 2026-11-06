#include <bits/stdc++.h>
using namespace std;

int priority(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPostfix(string expr)
{
    stack<char> st;
    string output = "";

    for (char c : expr)
    {
        if (isalnum(c))
        {
            output += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                output += st.top();
                st.pop();
            }
            st.pop();
        }
        else if (isOperator(c))
        {
            while (!st.empty() && priority(st.top()) >= priority(c))
            {
                output += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty())
    {
        output += st.top();
        st.pop();
    }

    return output;
}
