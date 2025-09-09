#include<iostream>
using namespace std;

class company {
    int d;
    int* size;
    int** sal;
public:
    company(int dep) {
        d = dep;
        size = new int[d];
        sal = new int*[d];
        for(int i=0;i<d;i++){
            cout<<"Enter number of employees in dept "<<i+1<<": ";
            cin>>size[i];
            sal[i] = new int[size[i]];
            for(int j=0;j<size[i];j++){
                cout<<"Enter salary of emp "<<j+1<<": ";
                cin>>sal[i][j];
            }
        }
    }
    void highest_each() {
        for(int i=0;i<d;i++){
            int max=sal[i][0];
            for(int j=1;j<size[i];j++)
                if(sal[i][j]>max) max=sal[i][j];
            cout<<"Dept "<<i+1<<": "<<max<<endl;
        }
    }
    void max_avg_dept() {
        int dep=0; double maxavg=0;
        for(int i=0;i<d;i++){
            double sum=0;
            for(int j=0;j<size[i];j++) sum+=sal[i][j];
            double avg=sum/size[i];
            if(avg>maxavg){maxavg=avg;dep=i;}
        }
        cout<<"Dept with max avg salary: "<<dep+1<<endl;
    }
    ~company() {
        for(int i=0;i<d;i++) delete[] sal[i];
        delete[] sal;
        delete[] size;
    }
};

int main(){
    int d;
    cout<<"Enter number of departments: ";
    cin>>d;
    company c(d);
    c.highest_each();
    c.max_avg_dept();
    return 0;
}
