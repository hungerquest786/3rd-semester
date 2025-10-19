#include<iostream>
using namespace std;

class queue 
{
    public:
    int arr[5];
    int head;
    int tail;
    int index;
    int max_limit;

    queue()
    {
        head = 0;
        tail = -1;
        index = 0;
        max_limit = 5;
    }

    void push (int a)
    {
        if (max_limit <= index)
        {
            cout << "queue overflow" << endl;
            return;
        }

        tail++;
        arr[tail] = a;
        index++;
    }

    void pop ()
    {
        if (index <= 0)
        {
            cout << "queue underflow" << endl;
            return;
        }

        cout << arr[head] << " is popped" << endl;
        head++;
        index--;

        if (index == 0)
        {
            head = 0;
            tail = -1;
        }
    }

    void top ()
    {
        if (index <= 0)
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "top data is : " << arr[head] << endl;
    }

    void display ()
    {
        if (index <= 0)
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue contents:" << endl;
        for (int i = head; i <= tail; i++)
        {
            cout << arr[i] << endl;
        }
    }
};

int main ()
{
    queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.display();
    q.pop();
    q.display();
    q.top();
    q.push(40);
    q.push(50);
    q.push(60);
    q.display();

    return 0;
}
