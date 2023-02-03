#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class queue
{
    Node *front;
    Node *rear;

public:
    queue()
    {
        front = NULL;
        rear = NULL;
    }
    // inserting element in the queue
    void enqueue(int newItem)
    {
        Node *newNode = new Node(newItem);

        if (front == NULL)
        {
            front = newNode;
            rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    // deleting element form the queue

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "The queue is Underflow.." << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        delete temp;
    }
    // showing the peek element

    int peek()
    {
        if (front == NULL)
        {
            cout << "There is no element in the queue.." << endl;
            return -1;
        }
        Node *temp = front;
        cout << "The peek element is : " << temp->data;
        return front->data;
    }
};

int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    // display 1 as a peek element
    q.peek();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    // display there is no element in the queue
    q.peek();
    return 0;
}