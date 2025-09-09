#include<iostream>
#include<string>

using namespace std;

class node 
{
    public:
    int data;
    node*next;

    node(int n)
    {
        this->data = n;
        this->next = NULL;
    }
};


int main ()
{
    node*n= new node(4);
    cout << n->data << endl << n->next << endl;

    
    return 0;
}