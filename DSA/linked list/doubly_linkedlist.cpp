#include<iostream>
#include<string>

using namespace std;

class node 
{
    public:
    int data;
    node*next;
    node*prev;

    node(int a)
    {
        data = a;
        this->next = NULL;
        this->prev = NULL;
    }
};

void getlength (node * &head)
{
    node*temp = head;
    int length;
    do
    {
        length++;
        cout << temp ->data<<endl;
        temp = temp->next;
    } while (temp != NULL);// use while coz it wil count head for length or head = null;
}

void insert_at_head(node* &head , int a )
// always take reference 
{
    // create new node 
    node*temp = new node(a);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insert_at_tail(node*&head, int a)
{
    if (head == NULL)
    {
        head = new node(a);
        return;
    }
    
    node * temp = head;
    // temp set to loop the needed pointer
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node*temp2 = new node (a);
    temp2->prev = temp;
    temp->next = temp2;
}

void insert_at_position (int position , int a, node*&head)
{

    if (position == 1) {
        node* newNode = new node(a);
        newNode->next = head;
        head -> prev = newNode;
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
    newtemp->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newtemp;  // chain fixing as temp next still points to old next and old next prev points to temp to fix that 
    }

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
        if (head!=NULL)
        {
            head->prev = NULL;
        }
        
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
    if (delete_node->next != NULL) {   
        delete_node->next->prev = temp;
    }// or delete_node->prev
    temp->next = delete_node->next;
    delete delete_node;
    
}


int main ()
{

}