#include <iostream>
#include <string.h>
#include <map> 
using namespace std;

void Swap(int * a, int * b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void PrintArray(int ar[], int len)
{
    for (int i = 0; i < len; i++)
        cout<<ar[i]<<" ";

    cout<<endl;
}

// int * Rotate(int * ar, int len, int steps)
// {
//     /*Rotate an array of (n=len) elements to the right by (k=steps) steps.*/
//     int * temp = new int[steps];

//     for(int i =0; i<steps; i++)
//         temp[i] = ar[i];

//     //shifting the elements 
//     for(int i = steps; i<len; i++)
//         ar[i - steps] = ar[i];

//     for(int i = len-steps, h = 0; i<len; i++, h++)
//         ar[i] = temp[h];

//     delete [] temp;
//     return ar;
// }

int * Rotate(int * ar, int len, int steps)
{
    /*Rotate an array of (n=len) elements to the right by (k=steps) steps without extra memory.*/

    //swapping the elements 
    int b;
    for(int i = 0; i<steps; i++)
    {
        b = 0;
        int temp = ar[b];

        for(; b < len -1; b++)
        {
            ar[b] = ar[b + 1];
        }
        ar[b] = temp;
    }

    return ar;
}

bool Isomorphic(string a, string b)
{
    if(a.length() != b.length())
        return false;

    if(a.length() == 0 && b.length() == 0)
        return true;

    map<char, char> chars;

    for(int i = 0; i<a.length(); i++)
    {
        char ac = a[i];
        char bc = b[i];

        if(chars.find(ac) != chars.end())
        {
            if(chars.find(ac)->second != bc)
                return false;
        }
        else
        {
            chars[ac] = bc;
        }
    }
    return true;
}

void Merge(int a [], int aSize, int b[], int bSize)
{   
    //merge two sorted arrays
    //assuming a has enough room to hold the elements of b

    while( aSize> 0 && bSize > 0)
    {
        if(a[aSize -1] >= b[bSize - 1])
        {
            a[aSize + bSize - 1] = a[aSize -1];
            aSize--;
        }
        else
        {
            a[aSize + bSize -1] = b[bSize - 1];
            bSize--;
        }
    }

    while(aSize > 0)
    {
        a[aSize + bSize - 1] = a[aSize -1];
            aSize--;
    }

    while(bSize > 0)
    {
        a[aSize + bSize -1] = b[bSize - 1];
            bSize--;
    }
}

void Merge(int left [], int leftSize, int right [], int rightSize, int * original)
{
    int i = 0, j = 0, k = 0;

    while(i < leftSize && j < rightSize)
    {
        if(left[i] <= right[j])
        {
            original[k] = left[i];
            i++;
        }
        else
        {
            original[k] = right[j];
            j++;
        }
        k++;
    }

    while(i<leftSize)
    {
        original[k] = left[i];
        i++; k++;
    }

    while(j<rightSize)
    {
        original[k] = right[j];
        j++; k++;
    }
}

void MergeSort(int * ar, int len)
{
    if(len < 2)
        return;

    int mid = len / 2;
    int left [mid];
    int right[len - mid];

    for(int i = 0; i< mid; i++)
        left[i] = ar[i]; 

    for (int i = mid; i < len; ++i)
        right[i - mid] = ar[i];

    MergeSort(left, mid);
    MergeSort(right, len - mid);
    Merge(left, mid, right, len - mid, ar);

}

// void Permutate()
// void PrintPermutation(int ar[], int len, int k)
// {   

// }
//////////////////////////////////////////////////////////////////Driver functions////////////////////////////////////////////////////////////////////
void RotateTest()
{
    int ar[7]= {1,2,3,4,5,6,7};

    cout<<"Before rotation:"<<endl;
    PrintArray(ar, 7);

    int * b = Rotate(ar, 7, 2);

    cout<<"After rotation:"<<endl;
    PrintArray(ar, 7);

    cout<<endl;
}

void MergeSortTest()
{
    int arr[] = {50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80};

    int arr_size = sizeof(arr)/sizeof(arr[0]);

    cout<<"Before: "<<arr_size<< endl;
    PrintArray(arr, arr_size);

    MergeSort(arr, arr_size);

    cout<<"After: "<<arr_size<<endl;
    PrintArray(arr, arr_size);

    cout<<endl;
}

int main(void)
{ 
   RotateTest();
    return 0;
}

 