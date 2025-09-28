#include<iostream>
#include<string>

using namespace std;

void function_B(int n);
int direct_recursion (int n)
{
    if (n == 1)
    {
        cout<<1<<endl;
        return 1;
    }else 
    {
        cout << n;
        return direct_recursion(n-1);
    }
}


// indirect
void function_A(int n)
{
    cout << n << " ";
    if (n==1)
    {
        cout << endl;
        return ;
    }
    function_B(n-1);
}

void function_B(int n)
{
    cout << n << " ";
    if (n==1)
    {
        cout << endl;
        return ;
    }
    function_A(n-1);
    
}

int main ()
{
    direct_recursion(4);
    function_A(6);
    function_B(3);
}