/*Convert infix expression to postfix expression..
Algorithm:
->If operand
print
->If '('
push to the stack
->If ')'
pop from the stack and print untill the '('is found then
->if operator
if the operator is of equal or less precedace is found
pop the operator on the top of the stack and push it into
the stack
If operator of the greator precedance is found then
print it
*/
#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int checkPrecedance(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixToPostfix(string s)
{
    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++)
    {
        // operand is printing
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')
        {
            res += s[i];
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
                res += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            // checking the precedance of the operator
            while (!st.empty() && checkPrecedance(st.top()) > checkPrecedance(s[i]))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    // printing the operator from the stack
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    return res;
}

int main()
{
    string str;
    cout << "Enter any infix expression : ";
    getline(cin, str);
    cout << infixToPostfix(str) << endl;
    return 0;
}