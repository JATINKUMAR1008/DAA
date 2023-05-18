#include<iostream>
using namespace std;
int board[20],n;

int place(int row,int col){
    for(int i=1;i<=row-1;i++){
        if(board[i]==col)
            return 0;
        if(abs(board[i]-col)==abs(i-row))
            return 0;
    }
    return 1;
}

void print(int);

void queen(int row,int col){
    for(int i=1;i<=col;i++){
        if(place(row,i)){
            board[row]=i;
            if(row==col){
                print(col);
            }
            else{
                queen(row+1,col);
            }
        }
    }
}

void print(int n){
    cout<<"Solution of the problem"<<endl;
    for(int i=1;i<=n;i++){
        cout<<"\t"<<i;
    }
    for(int i=1;i<=n;i++){
        cout<<"\n\n"<<i;
        for(int j=1;j<=n;j++){
            if(board[i]==j){
                cout<<"\tQ";
            }
            else{
                cout<<"\t-";
            }
        }
        cout<<endl;
    }
}


int main(){
    cin>>n;
    queen(1,n);
}