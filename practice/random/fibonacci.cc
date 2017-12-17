#include<iostream>

using namespace std;
#define MAX 45
#define UNKNOWN -1
long fib[MAX];

long fibonacci(int n){
    if(n==0) return 1;
    if(n==1) return 1;

    return fibonacci(n-1)+fibonacci(n-2);
}

long fibonacci_fast(int n){
    if(fib[n]==UNKNOWN)
        fib[n] = fibonacci_fast(n-1)+fibonacci(n-2);

    return fib[n];
}

long fibonacci_dp(int n){
    for(int i=2; i<=n; i++)
        fib[i] = fib[i-1] + fib[i-2];
    
    return fib[n];
}

int main(void){
    fib[0]=1;
    fib[1]=1;

    for(int i=2; i<MAX; i++){
        fib[i]=UNKNOWN;
    }

    int n;
    cin>>n;
    cout<<"Slow: "<<fibonacci(n)<<endl;
    cout<<"Cache: "<<fibonacci_fast(n)<<endl;
    cout<<"Iter DP: "<<fibonacci_dp(n)<<endl;
}
