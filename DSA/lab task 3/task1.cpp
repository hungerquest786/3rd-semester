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

class linked_list
{
    public:
    node*head;

    linked_list()
    {
        head = NULL;
    }

    node* reverse ()
    {
        node*reverse;
        int count = getlength();
        node*head2;
        
        while (1)
        {
            if (count == getlength())
            {
                reverse = new node (transverse(count)->data);
                head2 = reverse;
            }
            node * temp3 =  new node (transverse(--count)->data);
            reverse->next = temp3;
            reverse = reverse->next;
            if(!count)
            {
                break;
            }
        }
        
        return head2;
    }

    int getlength()
    {
        node*temp = head;
        int length;
        while ( temp != NULL)
        {
            temp = temp->next;
            length++;
        }

        return length;
    }

    node* transverse (int pos)
    {
        node*temp = head;
        for (size_t i = 0; i < pos-1; i++)       
        {
            temp = temp->next;
        }

    return temp;
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

    void display()
    {
        node*temp = head;
        while (temp !=NULL)
        {
            cout << temp->data;
            temp = temp->next;
        }
        
    }

    bool palindrome ()
    {
        node*Reverse;
        Reverse = reverse();
        int count = getlength();
        count = (count-1)/2;
        node*temp = head;
        while (count--)
        {
            if (Reverse->data != temp->data)
            {
                return false;
            }

            Reverse = Reverse->next;
            temp = temp->next;
            
        }

        return true;
    }
};

int main ()
{

}