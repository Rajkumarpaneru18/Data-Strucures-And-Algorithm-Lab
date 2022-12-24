/*program to perform the operation in deque
        a. Add at beginning
        b. Add at end
        c. Delete from beginning
        d. Delete from end

*/
#include <iostream>
#define max_Size 5
using namespace std;

class deque
{
private:
    int front;
    int rear;
    int arr[max_Size];

public:
    deque()
    {
        front = -1;
        rear = -1;
    }
    //adding new element at begining of the queue

    void addAtBegining(int newItem)
    {
        if ((front == 0 && rear == max_Size - 1) || front == (rear + 1))
        {
            cout << "The queue is full" << endl;
        }
        else if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            arr[front] = newItem;
        }
        else if (front == 0)
        {
            front = max_Size - 1;
            arr[front] = newItem;
        }
        else
        {
            --front;
            arr[front] = newItem;
        }
    }
//adding element fron end
    void addAtEnd(int newItem)
    {
        if ((front == 0 && rear == max_Size - 1) || front == (rear + 1))
        {
            cout << "The queue is full" << endl;
        }
        else if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            arr[rear] = newItem;
        }
        if (rear == max_Size - 1)
        {
            rear = 0;
            arr[rear] = newItem;
        }
        else
        {
            rear++;
            arr[rear] = newItem;
        }
    }
    //displaying the element in the list
    void display()
    {
        int i = front;
        while (i != rear)
        {
            cout << arr[i] << endl;
            i = (i + 1) % max_Size;
        }

        cout << arr[rear] << endl;
    }
//removing from front
    void dequeueFromfront()
    {
        if (front == -1 && rear == -1)
        {
            cout << "The queue is empty" << endl;
        }
        else if (front == max_Size - 1)
        {
            cout << "The element which is dequeued is:" << arr[front];
            front = 0;
        }
        else if (front == rear)
        {
            cout << "The element which is dequeued is:" << arr[front];
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }
    //removing from back
    void dequeueFromrear()
    {
        if (front == -1 && rear == -1)
        {
            cout << "The queue is empty" << endl;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else if (rear = 0)
        {
            cout << "The element which is dequeued is:" << arr[rear];
            rear = max_Size - 1;
        }
        else
        {
            rear--;
        }
    }
};
int main()
{
    deque d;
    d.addAtBegining(5);
    d.addAtBegining(6);
    d.addAtEnd(7);
    d.display();//print 6 5 7 ..
    return 0;
}