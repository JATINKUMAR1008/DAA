#include<iostream>
using namespace std;

int recursive(int arr[],int s,int f,int key){
    int mid = (s+f)/2;
    if(arr[mid]==key){
        return mid;
    }
    else if (key>arr[mid])
    {
        recursive(arr,mid+1,f,key);
    }else{
        recursive(arr,s,mid-1,key);
    }
    
}

int loop(int arr[],int key,int s,int f){
    while(s<f){
        int mid = (s+f)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(key>arr[mid]){
            s = mid+1;
        }else{
            f = mid-1;
        }
    }
}

int main(){
    cout<<"Binary Search: ";
    int arr[] = {1,3,5,7,9,11,13,15,17,19};
    int key;
    cout<<"Enter the key: ";
    cin>>key;
    int s = 0;
    int f = sizeof(arr)/sizeof(arr[0])-1;
    cout<<"Binary Search Recursive: ";
    cout<<recursive(arr,s,f,key)<<endl;
    cout<<"Binary Search Loop: ";
    cout<<loop(arr,key,s,f);

}