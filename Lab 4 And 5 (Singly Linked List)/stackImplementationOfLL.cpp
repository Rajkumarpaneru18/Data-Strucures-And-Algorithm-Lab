#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class linkedList
{
    Node *head;

public:
    linkedList()
    {
        head = NULL;
    }
    // push operation
    void push(int newData)
    {
        Node *temp = new Node();
        temp->data = newData;
        temp->next = head;
        head = temp;
        cout << "Element " << newData << "is pushed into the stack.." << endl;
    }
    // pop operation
    void pop()
    {
        if (head == NULL)
        {
            cout << "The stack is empty" << endl;
            return;
        }
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;

        delete temp;
    }

    // top of the stack
    int top()
    {
        if (head == NULL)
        {
            cout << "The stack is empty.." << endl;
            return -1;
        }
        cout << "\n Top element of the stack is: " << head->data << endl;

        return head->data;
    }
    // check the stack is empty or not
    int empty()
    {
        if (head == NULL)
        {
            cout << "The stack is empty.." << endl;
            return 1;
        }
        cout << "The stack is not empty" << endl;
        return 0;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "The stack is empty!!" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
int main()
{
    linkedList Ll;
    Ll.push(4);
    Ll.push(5);
    Ll.push(6);
    Ll.push(7);
    // display all the element of the stack
    Ll.display();
    Ll.pop();
    Ll.pop();
    Ll.pop();
    // display 4 as top of stack
    Ll.top();
    Ll.pop();
    // display the stack is empty
    Ll.empty();

    return 0;
}