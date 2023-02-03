/*
WRITE AN ALGORITHM AND PROGRAM FOR FOLLOWING CASES IN SINGLY
LINEAR LINKED LIST:
1. INSERTION OPERATIONS
a. INSERT NODE AT BEGINNING OF THE LIST
b. INSERT NODE AT END OF THE LIST
c. INSERT NODE AFTER SPECIFIC NODE
d. INSERT NODE BEFORE SPECIFIC NODE
2. DELETION OPERATIONS
a. DELETE NODE FROM BEGINNING OF THE LIST
b. DELETE NODE FROM END OF THE LIST
c. DELETE NODE AFTER SPECIFIC NODE
*/

#include <iostream>
using namespace std;

// creating a class named as node

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class linkedList
{
    node *head;

public:
    linkedList()
    {
        head = nullptr;
    }

    // insertion of a ndoe at begining
    void addNodeAtFirst(int data)
    {
        node *new_node = new node(data);
        new_node->next = head;
        head = new_node;
    }

    // to delete the first node

    void deleteFirstNode()
    {
        node *toDelete = head;
        head = head->next;

        delete toDelete;
    }

    // insertion of a node at End
    void insertAtEnd(int val)
    {
        // creating a new node
        node *n = new node(val);

        if (head == NULL)
        {
            head = n;
            return;
        }
        node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }

    // deletion from end of the linked list
    void deleteNodeFromEnd()
    {
        node *temp = head;

        if (head == NULL)
        {
            return;
        }
        if (head->next == NULL)
        {
            deleteFirstNode();
            return;
        }
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        node *toDelete = temp->next;
        delete toDelete;
        temp->next = NULL;
    }

    // insertion of node after specific postion
    void insertAfter(int val, int after)
    {
        node *newNode = new node(val);
        node *temp = head;

        while (temp->data != after)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // insertion of node before specific position
    void insertBefore(int data, int node_data)
    {
        node *new_node = new node(data);
        new_node->next = NULL;
        if (head->data == node_data)
        {
            new_node->next = head;
            head = new_node;
            return;
        }
        node *curr = head;
        while (curr->next != NULL)
        {
            if (curr->next->data == node_data)
            {
                new_node->next = curr->next;
                curr->next = new_node;
                return;
            }
            curr = curr->next;
        }
        cout << node_data << " not found.";
    }

    // delition of a node from specific position

    void deletionOfNode(int val)
    {
        node *temp = head;

        if (head == NULL)
        {
            return;
        }
        if (head->next == NULL)
        {
            deleteFirstNode();
            return;
        }

        while (temp->next->data != val)
        {
            temp = temp->next;
        }
        // to delete the node

        node *toDelete = temp->next;
        temp->next = temp->next->next;

        delete toDelete;
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{

    linkedList ls;
    ls.insertAtEnd(5);
    ls.insertAtEnd(4);
    ls.display();
    ls.addNodeAtFirst(3);
    ls.display();
    ls.insertAfter(2, 4);
    ls.display();
    ls.insertBefore(1, 5);
    ls.display();
    ls.deleteFirstNode();
    ls.display();

    ls.deleteNodeFromEnd();
    ls.display();
    ls.deletionOfNode(5);
    ls.display();
    return 0;
}