#include <iostream>
#include <algorithm>

using namespace std;

class Job {
public:
  char id;
  int deadline;
  int profit;

};

bool compareJobs(const Job& job1, const Job& job2) {
  return job1.profit > job2.profit;
}

void job_print(Job arr[],int n){
    sort(arr,arr+n,compareJobs);
    int result[n];
    bool slot[n];

    for(int i=0;i<n;i++){
        slot[i]=false;
    }
    for(int i=0;i<n;i++){
        for(int j=arr[i].deadline-1;j>=0;j--){
            if(!slot[j]){
                result[j]=i;
                slot[j]=true;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(slot[i]){
            cout<<arr[result[i]].id<<"  ";
        }
    }

}

int main() {
    Job arr[] = {
        {'W', 1, 19},
        {'V', 2, 100},
        {'X',2,27},
        {'Y',1,25},
        {'Z',3,1}
    };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Best way is: "<<endl;
    job_print(arr,n);
}