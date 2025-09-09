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
        data = a;
        this->next = NULL;
    }
};

class linked_list
{
    public:
    node*head;
    node*current_for_reverse;
    linked_list()
    {
        head = NULL;
    }
    void add_node_at_end (int a)
    {
        if (head == NULL)
        {
            head = new node(a);
            return;
        }

        node*temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        node*temp2 = new node (a);
        temp->next = temp2;
        
    }

        node* reverse (int count ,node*&head_given)
    {
        node*prev = NULL;
        node*current = head_given;
        node * next = NULL;

        while (count--)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;

            if (current == NULL)
            {
                return  prev;
            }
            

        }
        current_for_reverse = current;
        return prev; // new head
        
    }

    void pos_reverse  (int a)
    {
        node*l1 = reverse(a,head);
        node*l2;
        int n = getlength()/a;
        if (l1 == NULL)
        {
            display(l1);
            return;
        }else
        {
            do
            {
               l2 = reverse(a,current_for_reverse);
               node*temp = l1;
               while (temp->next != NULL)
               {
                 temp = temp->next;
               }
               temp->next = l2;
               
            } while (n--);

            display(l1);
            return;
            
        }
        
    }

    int getlength()
    {
        int length=0;
        node*temp = head;
        while (temp != NULL)
        {
            length++;
            temp = temp->next;
        }

        return length;
    }

    void operator+ (linked_list &other)
    {
        node*temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = other.head;
        
    }

    void display (node*&given_head)
    {
        node*temp = head;
        while (temp != NULL)
        {
            cout << temp->data;
            temp = temp->next;
        }
        
    }


};

int main ()
{
    linked_list l1;

    for (int i = 1; i <= 8; i++) {
        l1.add_node_at_end(i);
    }

    cout << "Reversing in groups of 3:" << endl;
    l1.pos_reverse(3);

    cout << endl;
    return 0;
}