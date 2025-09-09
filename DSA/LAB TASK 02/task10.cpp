 #include<iostream>
using namespace std;

class library {
    int cat;
    int* size;
    int** books;
public:
    library(int c){
        cat=c;
        size=new int[cat];
        books=new int*[cat];
        for(int i=0;i<cat;i++){
            cout<<"Enter number of books in category "<<i+1<<": ";
            cin>>size[i];
            books[i]=new int[size[i]];
            for(int j=0;j<size[i];j++){
                cout<<"Enter book id: ";
                cin>>books[i][j];
            }
        }
    }
    void search(int id){
        bool found=false;
        for(int i=0;i<cat;i++){
            for(int j=0;j<size[i];j++){
                if(books[i][j]==id){
                    cout<<"Book found in category "<<i+1<<endl;
                    found=true;
                }
            }
        }
        if(!found) cout<<"Book not found"<<endl;
    }
    ~library(){
        for(int i=0;i<cat;i++) delete[] books[i];
        delete[] books;
        delete[] size;
    }
};

int main(){
    int cat;
    cout<<"Enter number of categories: ";
    cin>>cat;
    library l(cat);
    int id;
    cout<<"Enter book id to search: ";
    cin>>id;
    l.search(id);
    return 0;
}
