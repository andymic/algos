#include<iostream>
#include<string>
using namespace std;

int findmatch(string source, string sub){
    int j,k;
    int y = source.length(), z = sub.length();

    for(j=0; j<(y-z); j++){
        k=0;
        while((k<y) && (source[j+k]==sub[k])){
            k++;
            if(k==z){
                return j;
            }
        } 
    }    
    return -1;
}

int main(void){
    string so, su;
    
    cin>>so;
    cin>>su;

    cout<<"Sequence starts at index: "<<findmatch(so,su)<<endl;    
    return 0;
}
