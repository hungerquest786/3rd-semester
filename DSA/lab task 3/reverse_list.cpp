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
        node*prev = NULL;
        node*current = head;
        node * next = NULL;

        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;

        }

        return prev; // new head
        
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
    linked_list l1;

    // Add elements
    l1.add_node_at_end(1);
    l1.add_node_at_end(2);
    l1.add_node_at_end(3);
    l1.add_node_at_end(2);
    l1.add_node_at_end(1);

    cout << "List: ";
    l1.display();

    if (l1.palindrome())
        cout << "\nThe list is a palindrome." << endl;
    else
        cout << "\nThe list is NOT a palindrome." << endl;

    return 0;
}