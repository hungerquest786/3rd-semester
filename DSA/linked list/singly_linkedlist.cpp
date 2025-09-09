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

void insert_at_head(node* &head , int a )
// always take reference 
{
    // create new node 
    node*temp = new node(a);
    temp->next = head;
    head = temp;
}

void transversal (node * &head)
{
    node*temp = head;
    do
    {
        cout << temp ->data<<endl;
        temp = temp->next;
    } while (temp != NULL);
}

void insert_at_tail(node*&head, int a)
{
    node * temp = head;
    if (head == NULL)
    {
        head = new node(a);
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node*temp2 = new node (a);
    temp->next = temp2;
}

void insert_at_position (int position , int a, node*&head)
{

    if (position == 1) {
        node* newNode = new node(a);
        newNode->next = head;
        head = newNode;
        return;
    }
    node * temp = head;
    for (size_t i = 1; i < position - 1; i++)
    {
        if (temp == NULL) 
        {
        cout << "Position out of range!" << endl;
        return;
        }
        temp = temp->next;
    }

    node*newtemp = new node(a);
    newtemp->next = temp ->next;
    temp->next = newtemp;
    
}

void deletion (node *&head , int position)
{
    if (head == NULL)
    {
        cout  << "not possible"<<endl;
        return;
    }

    if (position == 1) 
    {
        node* delete_node = head;
        head = head->next;
        delete delete_node;
        return;
    }
    // node before delete node
    node *temp = head;
    for (size_t i = 0; i < position - 2; i++)
    {
        if (temp == NULL || temp->next == NULL) // temp->null cant delete if there is no node ahead
        {
            cout << "Position out of range!" << endl;
            return;
        }
       temp = temp->next;
    }

    node*delete_node = temp->next;
    temp->next = delete_node->next;
    delete delete_node;
    
}

int main ()
{
    node*n= new node(4);
    //cout << n->data << endl << n->next << endl;
    node*head = n;
    transversal(head);
    insert_at_head(head, 5);
    transversal(head);

    
    return 0;
}