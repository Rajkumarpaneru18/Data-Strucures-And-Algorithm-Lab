/*Convert infix expression into postfix*/
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
// checking the precedance of the operator
int checkPrecedance(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' && c == '/')
    {
        return 2;
    }
    else if (c == '+' && c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixToPrefix(string s)
{
    reverse(s.begin(), s.end());
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
        {
            result += s[i];
        }
        // if'('is comes then push it into the stack

        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        // opertion when ')' comes

        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }

            if (!st.empty())
            {
                st.pop();
            }
        }

        else
        // checking the precedance of the operator

        {
            while (!st.empty() && checkPrecedance(st.top()) >= checkPrecedance(s[i]))
            {
                result += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    // printing the operator from the stack
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());
    return result;
}
int main()
{
    string s;
    cout << "Enter any infix expression." << endl;
    getline(cin, s);
    cout << infixToPrefix(s) << endl;
    return 0;
}