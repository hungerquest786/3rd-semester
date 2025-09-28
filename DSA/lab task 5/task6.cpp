#include <iostream>
using namespace std;

class maze {
    static const int n=4;
    int arr[n][n];
    int sol[n][n];
public:
    maze(int input[n][n]) {
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) {
            arr[i][j]=input[i][j];
            sol[i][j]=0;
        }
    }
    bool safe(int x,int y) {
        return (x>=0 && y>=0 && x<n && y<n && arr[x][y]==1);
    }
    bool find(int x,int y) {
        if(x==n-1 && y==n-1 && arr[x][y]==1) {
            sol[x][y]=1;
            return true;
        }
        if(safe(x,y)) {
            if(sol[x][y]==1) return false;
            sol[x][y]=1;
            if(find(x+1,y)) return true;
            if(find(x-1,y)) return true;
            if(find(x,y+1)) return true;
            if(find(x,y-1)) return true;
            sol[x][y]=0;
            return false;
        }
        return false;
    }
    void print() {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) cout<<sol[i][j]<<" ";
            cout<<endl;
        }
    }
};

int main() {
    int input[4][4]={
        {1,0,0,0},
        {1,1,0,1},
        {0,1,0,0},
        {1,1,1,1}
    };
    maze m(input);
    if(m.find(0,0)) m.print();
    else cout<<"no path"<<endl;
    return 0;
}
