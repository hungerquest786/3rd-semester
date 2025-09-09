#include"iostream"
#include"string"

using namespace std;
class bankaccount {
    public:
    string name;
    int account_no;
    
// bankaccount (){
//     name = 'x';
//     account_no = 0;
// }

bankaccount():name("x"), account_no(0){}
bankaccount (string a, int b){
    name = a;
    account_no = b;
}
bankaccount ( bankaccount &A)
{
    name = A.name;
    account_no = A.account_no;
}

};

int main ()
{ 
    bankaccount a;
    bankaccount B ("A", 0);
    bankaccount c(B);

    cout << "for a "<< a.name << endl;
    cout << "for b "<< B.name << endl;
    cout << "for c "<< c.name << endl;
}