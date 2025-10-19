#include<iostream>
using namespace std;

class Stack
{
    private:
    int arr[5];
    int index = -1;
    int capacity = 5; 

    public:

    void  push(int a)
    {
       if (index == capacity-1)
       {
        cout << "stack overflow"<<endl;
       }else 
       {
        arr[++index] = a;
        cout<<"in stack ="<<a<<endl;
       }
       
    }

    void pop()
    {
        if (index < 0 )
        {
            cout << "stack underflow"<<endl;
        }else
        {
            int x = arr[index--];
            cout << x <<endl;;
        }
        

    }

    void  top()
    {
        if (index < 0)
        {
            cout << "stack underflow"<<endl;
        }else 
        {
            cout << arr[index]<<endl;
        }
        
    }


    void display()
    {
        if (index < 0) {
            cout << "Stack is empty\n"; 
        } else {
            cout << "Stack elements: ";
            for (int i = 0; i <= index; i++) { 
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};



int main ()
{
    Stack stack;

    
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    
    stack.display();

    
    stack.push(60);

    
    stack.top();

   
    stack.pop();

   
    stack.display();

    
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();

    
    stack.pop();
    return 0;
}