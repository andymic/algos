#include<iostream>
using namespace std;

int main(void){

    int ar[]={0,1,2,1,0,2,1,0};

    int len = sizeof(ar)/sizeof(ar[0]);

    int r= 0;
    int b=len-1;

    for(int i=0; i<=b; i++){
        if(ar[i]==0 ){
            swap(ar[i], ar[r++]);
        }

        if(ar[i]==2) swap(ar[i--], ar[b--]);
    }

    for(auto i: ar)
        cout<<i<<" ";

    cout<<endl;
}
