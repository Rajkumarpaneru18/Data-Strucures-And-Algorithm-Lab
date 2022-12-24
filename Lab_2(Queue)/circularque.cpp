/*the enqueue dequeue operation in circular queue*/
#include <iostream>
#include <cmath>

using namespace std;
#define max_Size 5

class circularQueue
{
private:
    int arr[max_Size];
    int front;
    int rear;

public:
    circularQueue()
    {
        front = -1;
        rear = -1;
    }
    // enqueue operation in circular queue
    void enqueue(int x)
    {
        // checking the initial condition of the queue
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
            arr[rear] = x;
        }
        // checking whether the queue is full or not
        else if ((rear + 1) % max_Size == front)
        {
            cout << "The queue is full." << endl;
        }
        // increasing the value of the rear in circular queue
        else if (rear = (rear + 1) % max_Size)
        {
            arr[rear] = x;
        }
    }
    // Dequeue operation
    void dequeue()
    {
        // checking the queue is empty or not
        if (front == -1 && rear == -1)
        {
            cout << "The queue is empty" << endl;
        }
        // pointing the front and back in initial position if they are at Max_size-1
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            // increasing the front
            front = (front + 1) % max_Size;
        }
    }
    // checking the peek element of the queue
    void peek()
    {
        cout << arr[front] << endl;
    }
    // displaying the queue
    void display()
    {
        int i = front;
        // checking the queue is empty or not
        if (front == -1 && rear == -1)
        {
            cout << "The queue is empty" << endl;
        }

        else
        {
            cout << "The queue is :" << endl;
            while (i != rear)
            {
                cout << arr[i] << endl;
                i = (i + 1) % max_Size;
            }
            cout << arr[rear] << endl;
        }
    }
};
int main()
{
    circularQueue cq;//declaring the object of the class
    //inserting element in queue
    cq.enqueue(4);
    cq.enqueue(5);
    cq.peek();
    cq.enqueue(3);
    cq.enqueue(2);
    //reoving the element from the queue
    cq.dequeue();
    cq.dequeue();
    cq.dequeue();
    cq.dequeue();
    cq.display();//show that the queue is empty
    return 0;
}