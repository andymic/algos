#include<iostream>
#include<stdlib.h>
using namespace std;

void print(int *ar, int len){
    for(int i=0; i<len; i++){
        cout<<ar[i]<<",";
    }
    cout<<endl;
}

int partition(int *ar, int low, int high){
    int wall=low, pivot=high, i=low;

    for(; i<high; i++){
        if(ar[i]<ar[pivot]){
            swap(ar[i], ar[wall]);
            wall++;
        }
    }

    swap(ar[wall], ar[pivot]);
    print(ar, high);
    return wall;
}

void quick_sort(int *ar, int low, int high){
    int part;
    if((high-low)>0){
        part = partition(ar, low, high);
        quick_sort(ar, low, part-1);
        quick_sort(ar, part+1, high);
    }

}

int main(void){
    int ar[]={3,5,0,8,7,6,1,4};
    int ar_size = sizeof(ar)/sizeof(ar[0]);
    
    cout<<"Before sort\n";
    print(ar, ar_size);
    quick_sort(ar, 0, ar_size);
    cout<<"After sort\n";
    print(ar, ar_size);
    return 0;
}
