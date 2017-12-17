#include<iostream>

using namespace std;


double sqrt(int x){
    int i = 1;

    while(i*i<=x){
        i++;
    }
    
    return i-1;
}

double sqrt_b(int x){
    double min = 1;
    double max = x;
    double mid = 0;
    double result = 0;

    while(min <= max){

        mid = (min+max)/2;

        if(mid*mid == x){
            return mid;
        }

        if(mid*mid < x){
            min = mid+1;
            result = mid;
        }else{
            max = mid-1;
        }
    }
    return result;
}

float sqrt_babylonian(int x){
    float n = x;
    float y = 1;
    float e = 0.0000001;

    while(n-y>e){
        n = (n+y)/2;
        y = x/n;
    }
    return n;
}

int main(void){

    int n;
    cin>>n;

    cout<<sqrt(n)<<endl;
    cout<<sqrt_b(n)<<endl;
    cout<<sqrt_babylonian(n)<<endl;
}
