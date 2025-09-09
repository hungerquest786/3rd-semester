#include<iostream>
#include<string>

using namespace std;

class node 
{
    public:
    int data;
    node*next;

    node(int a)
    {
        next = NULL;
        data = a;
    }
};

class dnode 
{
    public:
    int data;
    dnode*next;
    dnode*prev;

    dnode(int a)
    {
        next = NULL;
        data = a;
        prev = NULL;
    }
};

class singly_linked_list 
{
    public:
    node*head;

    singly_linked_list()
    {
        head = NULL;
    }

    void add_node(int a)
    {
        if (head == NULL)
        {
            head = new node(a);
        }else{

        node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        
        node*temp2 = new node(a);
        temp->next = temp2;
        }
    }

    void convert_circular()
    {
        node*temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next=head;
    }

    dnode* convert_doubly()
    {
        node*temp = head;
        dnode*newnode = new dnode (head->data);
        dnode*temp_new = newnode;
        dnode*temp_old = NULL;
        temp = temp->next;
        if (head = NULL)
        {
            return newnode;
        }
        while (temp!=NULL)
        {
            
            temp_old = temp_new;
            temp_new = new dnode (temp->data);
            temp_old->next = temp_new;
            temp_new->prev = temp_old;
            temp = temp->next;
        }

        return newnode;
        
    }

    void print_singly() {
    node* temp = head;
    cout << "Singly: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void print_circular(int n) {  
    node* temp = head;
    cout << "Circular: ";
    for (int i = 0; i < n; i++) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    
}

void print_doubly(dnode* dhead) {
    cout << "Doubly forward: ";
    dnode* temp = dhead;
    
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    cout << "Doubly backward: ";

    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp -> prev;
    }
    

    cout << endl;
}

    
};



int main ()
{
        singly_linked_list s;

    // Add nodes
    s.add_node(1);
    s.add_node(2);
    s.add_node(3);
    s.add_node(4);

    cout << "Original Singly Linked List:" << endl;
    s.print_singly();

    cout << "\nAfter Conversion to Circular:" << endl;
    s.convert_circular();
    s.print_circular(8);

    cout << "\nAfter Conversion to Doubly:" << endl;
    dnode* dhead = s.convert_doubly();
    s.print_doubly(dhead);

    return 0;

}