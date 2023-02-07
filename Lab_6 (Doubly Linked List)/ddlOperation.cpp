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
// insertion at begining
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
// insertion at end
void insertAtEnd(int newIteam)
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
// insert before
void insertBeforeSpecificNode(int before, int val)
{
    Node *temp = head;
    while (temp->data != before)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(val);
    temp->prev->next = newNode;
    newNode->next = temp;
    temp->prev->prev = newNode->prev;
}
// insertion after
void insertionAfterSpecificNode(int after, int val)
{
    Node *temp = head;
    while (temp->data != after)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(val);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}
// delete From beginning
void deleteFromBegining()
{
    Node *temp = head;
    head = temp->next;
    head->prev = NULL;
    Node *toDelete = temp;
    delete toDelete;
}
// delete after
void deleteAfterSpecificNode(int after)
{
    Node *temp = head;

    while (temp->data != after)
    {
        temp = temp->next;
    }
    Node *toDelete = temp->next;
    temp->next = temp->next->next;
    temp->next->prev = temp;
    delete toDelete;
}
// delete before
void deleteBeforeSpecificNode(int before)
{
    Node *temp = head;
    while (temp->data != before)
    {
        temp = temp->next;
    }
    Node *toDelete = temp->prev;
    temp->prev = temp->prev->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp;
    delete toDelete;
}
// delete from end
void deleteFromEnd()
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *toDelete = temp;
    temp->prev->next = NULL;
    temp->prev = temp->prev->prev;
    delete toDelete;
}
// display Node data
void display()
{

    Node *temp = head;
    if (temp == NULL)
    {
        cout << "NULL" << endl;
    }

    while (temp != NULL)
    {
        cout << temp->data << "<->";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    insertAtBegining(3);
    insertAtBegining(2);
    insertAtBegining(1);
    insertAtEnd(4);
    display();
    insertBeforeSpecificNode(3, 5);
    display();
    insertionAfterSpecificNode(3, 6);
    display();
    deleteFromBegining();
    display();
    deleteFromEnd();
    display();

    deleteAfterSpecificNode(5);
    display();
    deleteBeforeSpecificNode(6);
    display();

    return 0;
}