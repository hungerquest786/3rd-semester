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

    void operator+ (linked_list &other)
    {
        node*temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = other.head;
        
    }

    void sort()
    {
        if (head == NULL || head->next == NULL) {
            return; // List is already sorted (0 or 1 element)
        }

        bool swapped;
        node* current;
        node* last = NULL;

        do {
            swapped = false;
            current = head;

            while (current->next != last) {
                if (current->data > current->next->data) {
                    // Swap the data values
                    int temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    swapped = true;
                }
                current = current->next;
            }
            last = current;
        } while (swapped);
    }

};




int main ()
{
    linked_list l1, l2;

    l1.add_node_at_end(5);
    l1.add_node_at_end(1);
    l1.add_node_at_end(9);
    l1.add_node_at_end(3);

    l2.add_node_at_end(8);
    l2.add_node_at_end(2);
    l2.add_node_at_end(7);
    l2.add_node_at_end(4);

    l1+l2;

    cout << "Before Sorting (concatenated list): ";
    node* temp = l1.head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    l1.sort();

    cout << "After Sorting: ";
    temp = l1.head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}