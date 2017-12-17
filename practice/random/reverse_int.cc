#include<iostream>
#include<climits>

using namespace std;

int reverse(int x){
    long long rev = 0;

    while(x){
        rev = rev * 10 + x%10;
        x /=10;
    }
    return (rev < INT_MIN || rev > INT_MAX)? 0 : rev;
}

int main(void){
    int i;
    cin>>i;
    cout<<reverse(i)<<endl;
}
