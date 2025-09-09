#include<iostream>
#include<string>

using namespace std;

class safe_pointer 
{
    public:
    int*num;
    safe_pointer(int n)
    {
        num = new int (n);
    }

    int getvalue()
    {
        if (num != NULL)
        {
            return *num;
        }else
        {
            return 0;
        }
        
    }

    void update_value(int n)
    {
        if (num != NULL)
        {
        //    num = new int (n); wrong coz it set new address you just need to update the value so :
        *num = n;
        }else
        {
         cout <<"not possible\n";
        }
    }

    void release ()
    {
        if (num != nullptr)
        {
            delete num;
        }
        num = nullptr;
        
    }

    ~safe_pointer()
    {
        release();
    }
};

int main ()
{
    const int n = 2;
    safe_pointer a[n] = {safe_pointer(1),safe_pointer(2)};
        for (int i = 0; i < n; i++) {
        cout << "Object " << i + 1 << ": " << a[i].getvalue() << endl;
    }

    return 0;

}