#include<iostream>
#include<string>

using namespace std;

class node 
{
    public:
    int data;
    node*next;
    node*flatten;

    node(int a)
    {
        next = NULL;
        data = a;
        flatten = NULL;
    }
};

class linked_list
{
    public:
    node*head;

    linked_list()
    {
        head = NULL;
    }

    void add_node_at_end (int a)
    {
        if (head == NULL)
        {
            head = new node(a);
            head->next = NULL;
        }else 
        {
            node*temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            node*temp2 = new node(a);
            temp->next = temp2;
            temp2->next = NULL;
            
        }
        
    }

    void add_flatten (int pos,int a)
    {
        
        node*temp = head;
        for (size_t i = 0; i < pos-1; i++)       
        {
            temp = temp->next;
        }
        if (temp->flatten == NULL)
        {
            temp->flatten = new node (a);
        }else if (temp->flatten != NULL)        
        {
            node*temp2 = temp->flatten;
            while (temp2->next != NULL)
            {
                temp2 = temp2->next;
            }
            node*temp3 = new node (a);
            temp2->next = temp3;
        }
        
    }

    void flatten_merge()
    {
        node*temp = head;
        if (temp == NULL)
        {
            return;
        }
        
        while (temp != NULL)
        {
            
            if (temp->flatten != NULL)
            {
                node*save = temp->next;
                node*temp2 = temp->flatten;
                temp->next = temp->flatten;
                while (temp2->next != NULL)
                {
                    temp2 = temp2->next;
                }
                temp2->next = save;
            }
            temp= temp->next;
        }
        

    }

    void display()
    {
        node*temp = head;
        while (temp !=NULL)
        {
            cout << temp->data;
            temp = temp->next;
            if (temp->flatten != NULL)
            {
                node*temp2 = temp;
                while (temp2->next != NULL)
                {
                    cout << temp2->data;
                    temp2 = temp2->next;
                }

            }
            
        }
        
    }


};

int main ()
{
    linked_list l;
    l.add_node_at_end(1);
    l.add_node_at_end(2);
    l.add_node_at_end(3);

    l.add_flatten(2, 4);
    l.add_flatten(2, 5);

    cout << "Original list (before flattening):" << endl;
    l.display();
    cout << endl;

    l.flatten_merge();

    cout << "Flattened list:" << endl;
    l.display();
    cout << endl;

    return 0;
}