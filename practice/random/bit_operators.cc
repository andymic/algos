#include <iostream>
#include <bitset>
using namespace std;

int main(void){
    int ar[5]= {1, 2, 2, 3, 1};

    int result = 0;
    for(int i =0; i<5; i++){
        result^=ar[i];
        bitset<3> x(result);
        cout<<x<<" ";
        cout<<((int)x.to_ulong())<<endl;
    }
    return 0;
}
