#include<iostream>
using namespace std;

class queue 
{
    public:
    int arr[5];
    int front;
    int rear;
    int max_limit;

    queue()
    {
        front = -1;
        rear = -1;
        max_limit = 5;
    }

    void push(int a)
    {
        if ((front == 0 && rear == max_limit - 1) || (rear + 1 == front))
        {
            cout << "queue overflow" << endl;
            return;
        }

        if (front == -1)
        {
            front = rear = 0;
            arr[rear] = a;
        }
        else
        {
            rear = (rear + 1) % max_limit;
            arr[rear] = a;
        }
        cout << a << " enqueued" << endl;
    }

    void pop()
    {
        if (front == -1)
        {
            cout << "queue underflow" << endl;
            return;
        }

        cout << arr[front] << " is popped" << endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % max_limit;
        }
    }

    void top()
    {
        if (front == -1)
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "top data is : " << arr[front] << endl;
    }

    void display()
    {
        if (front == -1)
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue contents:" << endl;
        int i = front;
        while (true)
        {
            cout << arr[i] << endl;
            if (i == rear)
                break;
            i = (i + 1) % max_limit;// best use case in iterative display (for myself)
        }
    }
};

int main()
{
    queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.display();
    q.pop();
    q.pop();
    q.push(60);
    q.push(70);
    q.display();
    q.top();
    return 0;
}
