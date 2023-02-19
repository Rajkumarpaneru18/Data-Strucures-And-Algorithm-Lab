/*Pr*/
#include <iostream>
using namespace std;
#define MAXSIZE 50

struct node
{
    int data;
    int next;
};

class Queue
{
    node Node[MAXSIZE];
    int avail, rear, front;
    // getNode
    int getNode()
    {
        if (avail == -1)
        {
            cout << "Overflow";
            exit(1);
        }
        int p = avail;
        avail = Node[avail].next;
        return p;
    }
    // freeNode
    void freeNode(int p)
    {
        Node[p].next = avail;
        avail = p;
    }

    void initialOrdering()
    {
        for (int i = 0; i < MAXSIZE - 1; i++)
            Node[i].next = i + 1;
        Node[MAXSIZE - 1].next = -1;
    }

public:
    Queue()
    {
        initialOrdering();
        avail = 0;
        rear = front = -1;
    }

    bool isEmpty()
    {
        return front == -1;
    }
    // enqueue operation

    void enqueue(int x)
    {
        int p = getNode();
        Node[p].data = x;
        Node[p].next = -1;
        if (rear == -1)
            front = rear = p;
        else
        {
            Node[rear].next = p;
            rear = p;
        }
    }
    // dequeue operation
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Underflow\n";
            return;
        }
        int p = front;
        front = Node[p].next;

        int item = Node[p].data;
        cout << "Deleted item = " << item << endl;
        if (front == -1)
            rear = -1;
        freeNode(p);
    }

    // display function
    void display()
    {

        if (isEmpty())
        {
            cout << "Empty queue\n";
            return;
        }
        int i = front;
        while (i != -1)
        {
            cout << Node[i].data << ' ';
            i = Node[i].next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    for (int i = 0; i < 6; i++)
        q.enqueue(i);
    q.display();
    for (int i = 0; i < 3; i++)
        q.dequeue();
    q.display();
}