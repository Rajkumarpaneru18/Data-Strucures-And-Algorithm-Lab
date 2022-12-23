/*Check the paired parenthesis in mathematical expression*/
#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<int> st;
    int n = s.size();
    bool ans = true;

    for (int i = 0; i < n; i++)
    {
        
        if (s[i] == '(' or s[i] == '[' or s[i] == '{')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (!st.empty() and st.top() == '(')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (s[i] == '}')
        {
            if (!st.empty() and st.top() == '{')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
        else if (s[i] == ']')
        {
            if (!st.empty() and st.top() == '[')
            {
                st.pop();
            }
            else
            {
                ans = false;
                break;
            }
        }
    }
    //checking the stack is empty or not
    if (!st.empty())
    {
        return false;
    }
    return ans;
}

int main()
{
    string s;
    cout << "Enter any expression :" << endl;
    getline(cin, s);
    //checking the validity of the parenthesis
    if (isValid(s))
    {
        cout << "The expression is balanced parenthesis." << endl;
    }
    else
    {
        cout << "The expression is not balanced." << endl;
    }
    return 0;
}
