#include <iostream>
using namespace std;


void print(int *ar, int len){
    for(int i=0; i<len; i++){
        cout<<ar[i]<<",";
    }
    cout<<endl;
}

int binary_search(int *ar, int low, int high, int val){
    if(low > high) return -1;
    
    int mid = high+low/2;    
       
    if(ar[mid]==val){
        cout<<"Found match"<<endl;
        return mid;
    }

    if(val<ar[mid]){
       binary_search(ar, low, mid-1, val);
    }else{
       binary_search(ar, mid+1, high, val);
    }
}

int main(void){
    int ar[]={0,1,2,3,4,5,6,7,8,9};
    int ar_size = sizeof(ar)/sizeof(ar[0]);
    int val;
    
    print(ar, ar_size);
    cout<<"Value to search for"<<endl;
    cin>>val;

    cout<<"Index :"<<binary_search(ar,0, ar_size, val);
    return 0;
}
