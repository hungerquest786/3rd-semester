#include<iostream>
using namespace std;

void sumtail(int n , int &total)
{
    if (n == 0)
    {
        return;
    }else 
    {
        total += n;
        sumtail(n-1,total);
    }
}

int sum_not_tail(int n)
{
    if (n == 0)
    {
        return 0;  
    }else
    {
        return n + sum_not_tail(n-1);
    }
}

int main ()
{
    int n ;
    int total = 0;  

    n = sum_not_tail(5);
    sumtail(5, total);

    cout << "sum_not_tail(5) = " << n << endl;
    cout << "sumtail(5) = " << total << endl;

    return 0;
}
