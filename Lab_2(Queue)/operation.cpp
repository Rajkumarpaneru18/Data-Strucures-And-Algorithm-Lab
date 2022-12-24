/*the operation on the Queue*/
#include <iostream>
using namespace std;
#define N 20

class queue
{
private:
    int *arr;//decalring array dynamically
    int front;
    int back;

public:
    queue()
    {
        arr = new int[N];
        front = -1;
        back = -1;
    }

    // enqueue Operation
    void push(int x)
    {
        if (back == N-1)
        {
            cout << "The queue is overflow." << endl;
            return;
        }
        back++;
        arr[back] = x;

        if (front == -1)
        {
            front++;
        }
    }
 //dequeue operation 
    void pop()
    {
        if (front == -1 || front > back)
        {
            cout << "No element in the queue" << endl;
            return;
        }
        else
        {
            front++;
        }
    }
    //checking the top element of the queue
    int peek()
    {
        if (front == -1 || front > back)
        {
            cout << "No element in the queue." << endl;
            return -1;
        }
        else
        {

            return arr[front];
        }
    }
    //checking whether the given queue is empty or not
    bool empty()
    {
        if (front == -1 || front > back)
        {
            return true;
        }
            return false;
    }
};
int main()
{
    queue q;
    q.push(3);
    q.push(4);
    q.push(5);
    cout << q.peek() << endl;//print 3
    q.pop();
    q.pop();
    cout << q.peek() << endl;//print 5
    q.pop();
    cout<<q.empty()<<endl;//return true  

    return 0;
}