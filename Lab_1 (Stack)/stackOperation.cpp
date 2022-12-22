/*Perform push and pop operations in stack*/

#include <iostream>
using namespace std;
// defining the maximum size of the array
#define Max_Size 20

class stack
{
private:
    int arr[Max_Size];
    int top;

public:
    // constructor to initialize the top
    stack()
    {
        top = -1;
    }
    // push operation
    void push()
    {
        int newItem;
        cout << "Enter number to push into the stack." << endl;
        cin >> newItem;
        if (top == Max_Size - 1)
        {
            cout << "The stack is overflow." << endl;
        }
        else
        {
            top++;
            arr[top] = newItem;
        }
    }

    // pop operation
    void pop()
    {
        if (top == -1)
        {
            cout << "The stack is underflow." << endl;
        }
        else
        {
            top--;
        }
    }
    // checking the top element of the stack
    void Top()
    {
        if (top == -1)
        {
            cout << "Nothing in the stack." << endl;
        }
        else
        {
            cout << arr[top] << endl;
        }
    }
    // To check the stack is empty or not
    bool empty()
    {
        return top = -1;
    }
};
int main()
{
    // creating the object of the stack
    stack st;
    int choice;

    do
    {
        cout << "Enter the option that you want to do." << endl;
        cout << "1.Push Into The Stack."
             << "2.Pop From The Stack "
             << "3.Top of stack ";
        cout << "4.Check The Stack"
             << "5.To exit" << endl;

        cin >> choice;
        switch (choice)
        {
        case 1:
            st.push();
            break;
        case 2:
            st.pop();
            break;

        case 3:
            st.Top();
            break;

        case 4:
            st.empty();
            break;
        }
    } while (choice != 5);
}
