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
        next = NULL;
    }
};

class circular_linked_list 
{
    public:
    node*head;

    circular_linked_list()
    {
        head = NULL;
    }

    void add_node(int a)
    {
        node*temp = head;

        if (head == NULL)
        {
            head = new node (a);
            head->next = head;
            return;
        }

        while (temp->next != head)
        {
            temp = temp->next;
        }

        node*temp2 = new node (a);
        temp2 -> next = head;
        temp->next = temp2;
        
    }

    void display()
    {
        if (head == NULL)
        {
            return;
        }
        
        node*temp = head;

        do
        {
            cout << temp->data;
            temp = temp->next;
        } while (temp != head);
        
    }

    void deletion (int pos)
    {
        
        node*temp = head;

        if (pos == 1) {
        while (temp->next != head) {  // move to last node
            temp = temp->next;
        }
        node* del = head;
        temp->next = head->next;
        head = head->next;
        delete del;
        return;
        }

        for (size_t i = 0; i < pos - 2; i++)
        {            
            temp=temp->next;
            // if ( i == pos-1 && temp==head )
            // {
            //     node*temp2 = head;
            //     do
            //     {
            //         temp2 = temp2->next;
            //     } while (temp2 != head);
                
            //     temp2->next=temp->next;
            // }else if (i == pos-1 && temp->next==head)
            // {
            //     node*temp2 = head;
            //     do
            //     {
            //         temp2 = temp2->next;
            //     } while (temp2->next->next != head);
            //     temp2->next = head;
               
            // }
        
        }

        node*del = temp->next;
        temp->next=temp->next->next;
        delete del;
        
    }



    };

int main ()
{
    circular_linked_list cll;

    // build list
    for (int i = 1; i <= 7; i++) {
        cll.add_node(i);
    }

    cout << "Initial circle: ";
    cll.display();
    cout << endl;

    while (cll.head != NULL && cll.head->next != cll.head) {
        int pos;
        cout << "Enter position to delete: ";
        cin >> pos;
        cll.deletion(pos);

        cout << "After deletion: ";
        cll.display();
        cout << endl;
    }

    if (cll.head != NULL) {
        cout << "Survivor: " << cll.head->data << endl;
    }

    return 0;
}