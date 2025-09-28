#include<iostream>
#include<string>

using namespace std;

int calculate_recurison (int n)
{
    if (n==1 || n== 0)
    {
        return 1;
    }else
    {
        return n*calculate_recurison(n-1);
    }
    
}

int main ()
{
    int a = calculate_recurison(5);
    cout<<a;
    return 0;
}