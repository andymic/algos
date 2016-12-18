#include<iostream>
using namespace std;


void swap(int *a, int *b){
    int temp =*a;
    *a=*b;
    *b=temp;
}

void print(int *ar, int len){

    for(int i=0; i<len; i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}

void selection_sort(int *ar, int len){
    int min=0, j = 0;

    for(int i=0; i<len-1; i++){
        min = i;
        for(j=i+1; j<len; j++){
            if(ar[j]<ar[min]){
                min=j;
            }
        }
        swap(&ar[min], &ar[i]);
        print(ar, len);
    }
}

int main(void){
    int ar[] = {23,12,4,16,8,15};
    int len = sizeof(ar)/sizeof(int);

    cout<<"length "<<len<<endl;

    selection_sort(ar, len);
    print(ar, len); 
    return 0;   
}
