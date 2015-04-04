#include <iostream>
#include <string> 

using namespace std;

bool BinarySearch(int digit, int ar[], int length)
{
    int middle=0;
    int lboundary=0, uboundary=length-1;
    for(int i=0; i<length; i++)
    {
        middle=(uboundary+lboundary)/2;
        if(ar[middle]==digit)
        {
            cout<<"Found at index: "<<middle<<endl;
            return true;
        }
        else if(ar[middle]>digit)
        {
            uboundary=--middle;
        }
        else if(ar[middle]<digit)
        {
            lboundary=++middle;
        }
    }
    return false;
}
int main(void)
{
    int ar[10]={1,2,3,4,5,6,7,8,9,10};
    BinarySearch(4, ar, 10);
 return 0;
}

 