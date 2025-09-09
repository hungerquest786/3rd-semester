#include"iostream"
#include"string"

using namespace std;

class exam 
{
    private:
    int a ;
    string * name;
    int * marks;
    int * date;
public :
    exam (int s){
        a = s;
        name = new string[s];
        marks = new int [s];
        date = new int [s];

        for (int i = 0 ; i < s ; i++)
        {
            cin >> name[i];
            cin >> marks[i];
            cin >> date[i];
        }
    }

    ~exam(){
        delete [] name;
        delete [] marks;
        delete [] date;
    }
     
    void display (){
        for (int i = 0 ; i < a ; i++){
        cout << name[i] <<endl;
        cout << marks[i] <<endl;
        cout << date[i] <<endl;
        }
    }


};
int main ()
{
    exam a (1);
    exam b = a;

    a.display();
    b.display();
}