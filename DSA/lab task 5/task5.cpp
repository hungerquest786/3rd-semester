#include <iostream>
using namespace std;

class sudoku {
    static const int n=9;
    int arr[9][9];
public:
    sudoku(int input[9][9]) {
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) arr[i][j]=input[i][j];
    }
    bool valid(int r,int c,int val) {
        for(int i=0;i<n;i++) if(arr[r][i]==val||arr[i][c]==val) return false;
        int sr=r-r%3,sc=c-c%3;
        for(int i=0;i<3;i++) for(int j=0;j<3;j++) if(arr[sr+i][sc+j]==val) return false;
        return true;
    }
    bool solve() {
        for(int r=0;r<n;r++) {
            for(int c=0;c<n;c++) {
                if(arr[r][c]==0) {
                    for(int val=1;val<=9;val++) {
                        if(valid(r,c,val)) {
                            arr[r][c]=val;
                            if(solve()) return true;
                            arr[r][c]=0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void print() {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) cout<<arr[i][j]<<" ";
            cout<<endl;
        }
    }
};

int main() {
    int input[9][9]={
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    sudoku s(input);
    if(s.solve()) s.print();
    else cout<<"no solution"<<endl;
    return 0;
}
