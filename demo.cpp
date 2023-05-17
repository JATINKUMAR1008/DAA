#include<iostream>
using namespace std;

static int m, n;

static int c = 0;

static int count = 0;

int g[50][50];

int x[50];

void nextvalue(int);

void graph(int k){
    while(1){
        nextvalue(k);
        if(x[k]==0){
            return ;
        }
        if(k==n){
            c=1;
            for(int i=1;i<=n;i++){
                cout<<x[i]<<" ";
            }
            count++;
            cout<<endl;
        }
        else{
            graph(k+1);
        }
    }
}

void nextvalue(int k){
    int j;
    while(1){
        x[k] = (x[k]+1)%(m+1);
        if(x[k]==0){
            return;
        }
        for(j=1;j<=n;j++){
            if(g[k][j]==1 && x[k] == x[j]){
                break;
            }
        }
        if(j==(n+1)){
            return;
        }
        
    }
}
int main(){
    int t;
    cout<<"Enter number of nodes: ";
    cin>>n;
    cout<<"Enter Adjacency matrix: ";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>g[i][j];
        }
    }
    for(m=1;m<=n;m++){
        if (c==1){
            break;
        }
        graph(1);
    }
    cout<<"Chromatic number: "<<count;
    cout<<"Solutions: "<<m-1;
    return 0;
}