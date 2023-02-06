/* Program to perform the operation of the doubly linked List*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};
Node *head = NULL;
void insertAtBegining(int val)
{

    Node *newNode = new Node(val);
    newNode->next = head;
    if (head != NULL)
    {
        head->prev = newNode;
    }
    head = newNode;
}
void insetAtEnd(int newIteam)
{
    Node *n = new Node(newIteam);

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}
void insertionAfterSpecificNode(Node *prevNode, int val)
{
    if (prevNode == NULL)
    {
        cout << "Previous node cannot be NULL" << endl;
        return;
    }

    Node *newNode = new Node(val);
    newNode->prev = prevNode;
    newNode->next = prevNode->next;
    prevNode->next = newNode;

    if (newNode->next != NULL)
        newNode->next->prev = newNode;
}

void insertBeforeSpecificNode(Node *Before, int val)
{
    if (Before == NULL)
    {
        cout << "Before Node can not be NULL" << endl;
        return;
    }
    Node *newNode = new Node(val);
    newNode->next = Before;
    newNode->prev = Before->prev;
    Before->prev = newNode;

    if (newNode->prev != NULL)
    {
        newNode->prev->next = newNode;
    }
}
void display()
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "<->";
        temp = temp->next;
    }
}
int main()
{
    insertAtBegining(1);
    insertAtBegining(2);
    insetAtEnd(3);
    insetAtEnd(4);
    insertionAfterSpecificNode(head->next, 5);
    insertBeforeSpecificNode(head->next->next, 6);
    display();
    return 0;
}