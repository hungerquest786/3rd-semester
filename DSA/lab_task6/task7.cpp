#include <iostream>
using namespace std;

class Process {
public:
    int id;
    int priority;

    Process() {
        id = 0;
        priority = 0;
    }

    Process(int a, int b) {
        id = a;
        priority = b;
    }
};

class Queue {
public:
    int front;
    int rear;
    int max_limit;
    Process arr[10];

    Queue() {
        front = -1;
        rear = -1;
        max_limit = 10;
    }

    bool isEmpty() {
        if (front == -1 || front > rear)
            return true;
        else
            return false;
    }

    bool isFull() {
        if (rear == max_limit - 1)
            return true;
        else
            return false;
    }

    void enqueue(Process p) {
        if (isFull()) {
            cout << "Queue overflow!" << endl;
            return;
        }
        if (front == -1)
            front = 0;
        rear++;
        arr[rear] = p;
    }

    Process dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow!" << endl;
            return Process(-1, -1);
        }
        Process temp = arr[front];
        front++;
        return temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Processes in Queue (Arrival Order):" << endl;
        for (int i = front; i <= rear; i++) {
            cout << "ID: " << arr[i].id << ", Priority: " << arr[i].priority << endl;
        }
    }
};

class Stack {
public:
    int topIndex;
    int maxSize;
    Process arr[10];

    Stack() {
        topIndex = -1;
        maxSize = 10;
    }

    bool isEmpty() {
        if (topIndex == -1)
            return true;
        else
            return false;
    }

    bool isFull() {
        if (topIndex == maxSize - 1)
            return true;
        else
            return false;
    }

    void push(Process p) {
        if (isFull()) {
            cout << "Stack overflow!" << endl;
            return;
        }
        arr[++topIndex] = p;
    }

    Process pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return Process(-1, -1);
        }
        return arr[topIndex--];
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Processes in Stack (Execution Order):" << endl;
        for (int i = topIndex; i >= 0; i--) {
            cout << "ID: " << arr[i].id << ", Priority: " << arr[i].priority << endl;
        }
    }
};

int main() {
    Queue arrival;
    Stack execution;

    arrival.enqueue(Process(1, 2));
    arrival.enqueue(Process(2, 1));
    arrival.enqueue(Process(3, 3));

    cout << "Initial Arrival Queue:" << endl;
    arrival.display();
    cout << endl;

    while (!arrival.isEmpty()) {
        Process p = arrival.dequeue();
        execution.push(p);
    }

    cout << "Stack after scheduling (Higher priority executed first):" << endl;
    execution.display();
    cout << endl;

    cout << "Executing processes (LIFO Order):" << endl;
    while (!execution.isEmpty()) {
        Process p = execution.pop();
        cout << "Executing Process ID: " << p.id << " | Priority: " << p.priority << endl;
    }

    return 0;
}
