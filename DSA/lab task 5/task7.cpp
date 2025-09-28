#include <iostream>
using namespace std;

class queens {
    int n;
    int arr[20][20];
public:
    queens(int size) {
        n=size;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) arr[i][j]=0;
    }
    bool safe(int r,int c) {
        for(int i=0;i<r;i++) if(arr[i][c]==1) return false;
        for(int i=r-1,j=c-1;i>=0&&j>=0;i--,j--) if(arr[i][j]==1) return false;
        for(int i=r-1,j=c+1;i>=0&&j<n;i--,j++) if(arr[i][j]==1) return false;
        return true;
    }
    void print() {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) cout<<arr[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    bool solve(int r) {
        if(r==n) {
            print();
            return true;
        }
        bool res=false;
        for(int c=0;c<n;c++) {
            if(safe(r,c)) {
                arr[r][c]=1;
                res=solve(r+1)||res;
                arr[r][c]=0;
            }
        }
        return res;
    }
};

int main() {
    int size;
    cout<<"enter n: ";
    cin>>size;
    queens q(size);
    q.solve(0);
    return 0;
}
