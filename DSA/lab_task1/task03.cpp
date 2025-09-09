#include"iostream"
#include"string"

using namespace std;

class box 
{
    public:
    int*s;
    
    box (int x){
        s = new int (x);
    }

    box(box &a)
    {
        s = new int (*a.s);
    }

    box operator= (box &a)
    {
        s = new int (*a.s);
    }
    

};

int main ()
{
    box a (1);
    box b = a ;
    box c (a);

    cout << " a is " << *a.s<<endl;
    cout << " b is " << *b.s<<endl;
    cout << " c is " << *c.s<<endl;
}