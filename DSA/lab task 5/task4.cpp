#include <iostream>
using namespace std;

class ack {
public:
    int fun(int a,int b) {
        if(a==0) return b+1;
        else if(a>0 && b==0) return fun(a-1,1);
        else return fun(a-1,fun(a,b-1));
    }
};

int main() {
    int a,b;
    cout<<"enter m and n: ";
    cin>>a>>b;
    ack obj;
    cout<<"ackermann("<<a<<","<<b<<") = "<<obj.fun(a,b)<<endl;
    return 0;
}
