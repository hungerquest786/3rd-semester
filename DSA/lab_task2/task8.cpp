#include<iostream>
using namespace std;

class city {
    int n,m;
    double** temp;
public:
    city(int days,int times){
        n=days; m=times;
        temp=new double*[n];
        for(int i=0;i<n;i++){
            temp[i]=new double[m];
            for(int j=0;j<m;j++){
                cout<<"Day "<<i+1<<" Time "<<j+1<<": ";
                cin>>temp[i][j];
            }
        }
    }
    void daily_avg(){
        double hottest=-1e9,coldest=1e9;
        int hotday=0,coldday=0;
        for(int i=0;i<n;i++){
            double sum=0;
            for(int j=0;j<m;j++) sum+=temp[i][j];
            double avg=sum/m;
            cout<<"Avg temp Day "<<i+1<<": "<<avg<<endl;
            if(avg>hottest){hottest=avg;hotday=i;}
            if(avg<coldest){coldest=avg;coldday=i;}
        }
        cout<<"Hottest Day: "<<hotday+1<<endl;
        cout<<"Coldest Day: "<<coldday+1<<endl;
    }
    ~city(){
        for(int i=0;i<n;i++) delete[] temp[i];
        delete[] temp;
    }
};

int main(){
    int n,m;
    cout<<"Enter days: ";
    cin>>n;
    cout<<"Enter times per day: ";
    cin>>m;
    city c(n,m);
    c.daily_avg();
    return 0;
}
