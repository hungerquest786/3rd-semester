#include <iostream>
#include <string>
using namespace std;

class node {
public:
    string data;
    node* next;
    node(string x) : data(x), next(nullptr) {}
};

class list {
public:
    node* head;
    list() : head(nullptr) {}

    void add_node(string x) {
        node* newNode = new node(x);
        newNode->next = head;
        head = newNode;
    }
    // while (temp->next != NULL) // { 
    // temp = temp->next; 
    // store2 = temp->data; 
    // temp->data =store; 
    // store2= store; 
    // } 
    // temp->data = store2; 
    // temp->next = new node (store); 
    // head->data = x; 
    // complicated
};

class stack {
    int top;
    int capacity;
public:
    list ll;

    stack(int cap = 10) : top(-1), capacity(cap) {}

    void push(string url) {
        if (top >= capacity - 1) {
            cout << "Stack overflow\n";
            return;
        }
        ll.add_node(url);
        top++;
        cout << "Visited: " << url << endl;
    }

    void pop() {
        if (top < 0) {
            cout << "No more history to go back to.\n";
            return;
        }
        cout << "Going back from: " << ll.head->data << endl;
        node* temp = ll.head;
        ll.head = ll.head->next;
        delete temp;
        top--;
    }

    void peek() {
        if (top < 0) {
            cout << "No pages currently open.\n";
        } else {
            cout << "Current page: " << ll.head->data << endl;
        }
    }

    void display() {
        if (ll.head == nullptr) {
            cout << "History is empty.\n";
            return;
        }
        cout << "Browser history (most recent first): ";
        node* temp = ll.head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    stack browserHistory;

    browserHistory.push("google.com");
    browserHistory.push("openai.com");
    browserHistory.push("github.com");

    browserHistory.display();

    browserHistory.peek();

    browserHistory.pop();
    browserHistory.peek();

    browserHistory.display();

    return 0;
}
