#include<iostream>

using namespace std;

void permutation(string s, int start, int end){

    if(start==end)
        cout<<s<<endl;
    else{
        for(int i=start; i<end; i++){
            swap(s[start], s[i]);
            permutation(s, start+1, end);
            swap(s[start], s[i]);
        }
    }
}
int main(void){
    permutation("abc",0,3);
    return 0;
}
