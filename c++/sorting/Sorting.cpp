#include <iostream>
#include <string> 

using namespace std;
void PrintAr(int ar[],int len)
{
    bool last=false;

    cout<<"[";
    for(int i=0; i<len; i++)
    {
        cout<<ar[i];
        if(i==len-1)last=true;

        if(!last)cout<<",";
    }
    cout<<"]";
}

int* BubbleSort(int ar[], int len)
{
    //Runtime is O(n^2)...not efficient for large data sets although it is stable and does not use additional space
    for(int i=0; i<len; i++)
    {
        for(int e=0; e<len; e++)
        {
            if(ar[e]>ar[e+1])
            {
                int temp=ar[e];
                ar[e]=ar[e+1];
                ar[e+1]=temp;
            }
        }
    }

    return ar;
}

int* InsertionSort(int ar[], int len)
{
    for(int i=0; i<len; i++)
    {
        int e=i;
        //Sorting the array up to i every iteration.
        //Most efficient is array is nearly sorted.
        while(e>0 && ar[e]<ar[e-1])
        {
            int temp=ar[e];
            ar[e]=ar[e-1];
            ar[e-1]=temp;
            e--;
        }
    }

    return ar;
}

int main(void)
{
    int ar[10]={1,5,3,7,0,8,6,2,4,9};
    int *res;


    res=InsertionSort(ar,10);
    PrintAr(res,10);
    return 0;
}
 