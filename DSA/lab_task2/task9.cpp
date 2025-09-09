#include<iostream>
using namespace std;

class sparse {
    int r,c;
    int** mat;
public:
    sparse(int rows,int cols){
        r=rows;c=cols;
        mat=new int*[r];
        for(int i=0;i<r;i++){
            mat[i]=new int[c];
            for(int j=0;j<c;j++){
                cout<<"Enter value ["<<i<<"]["<<j<<"]: ";
                cin>>mat[i][j];
            }
        }
    }
    void show_normal(){
        cout<<endl<<"Matrix:"<<endl;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++) cout<<mat[i][j]<<" ";
            cout<<endl;
        }
    }
    void show_compressed(){
        cout<<endl<<"Compressed form (row col val):"<<endl;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(mat[i][j]!=0) cout<<i<<" "<<j<<" "<<mat[i][j]<<endl;
    }
    ~sparse(){
        for(int i=0;i<r;i++) delete[] mat[i];
        delete[] mat;
    }
};

int main(){
    int r,c;
    cout<<"Enter rows and cols: ";
    cin>>r>>c;
    sparse s(r,c);
    s.show_normal();
    s.show_compressed();
    return 0;
}
