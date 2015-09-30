#include <iostream>
#include <string.h>
#include <random>

 using namespace std;

void RemoveDuplicates(char * s)
{
    bool * hash= new bool[256];

    for(int i=0; i<256; i++)
    {
        hash[i]=false;
    }
    string res="";

    int length=strlen(s);

    for(int i=0; i<length; i++)
    {
        int temp=s[i];
        if(hash[temp])
        {
            cout<<"Duplicates found "<<temp<<" or "<<s[i]<<endl;
        }
        else
        {
            hash[temp]=true; 
            res+=s[i];
        }
          
    } 
    cout<<"Result: "<<res;
}
void swap(char * a, char * b)
{
    char temp = *a;
    *a = *b;
    *b=temp;
}
void Permutate(char *a, int start, int len)
{
    int i;

    if(start == len)
        cout<<a<<endl;
    else
    {
        for(i = start; i<len; i++)
        {
            swap((a+start), (a+i));
            Permutate(a, start+1, len);
            swap((a+start), (a+i));
        }
    }
}

bool Anagram(char * a, char * b)
{

}

void BubbleSort(char * s, int len)
{
    //Runtime: On^2
    bool sorted;
    
    for(int a = 1; a<len-1; a++)
    {
        sorted = false;
        for( int i = 0; i<=len-a-1; i++)//avoids redudndant pass over sorted elements
        {
            if(s[i] > s[i+1])
            {
                swap(s[i], s[i+1]);
                sorted = true;
            }
        }
        
        if(!sorted)break; //avoids unecessary passes if string is already sorted
    }
}

void SelctionSort(int * s, int len)
{
    //swaps in place the current min vs the actual min
    for (int i = 0; i < len - 1; i++)
    {
        int  min = i;
        for (int m = i + 1; m<len ; m++)
        {
            if (s[m]<s[min])
                min = m;
        }

        int temp = s[i];
        s[i] = s[min];
        s[min] = temp;
    }
}

void Random()
{
    random_device rd; // obtain a random number from hardware
    mt19937 eng(rd()); // seed the generator
    uniform_int_distribution<> distr(1, 7); // define the range

    for(int n=0; n<10; ++n)
        std::cout << distr(eng) << ' '; // generate numbers
}

int main(void)
{
    int a[] = { 5,7,10,4,2,5,49,0,6 };
    SelctionSort(a, 9);

    for (int i = 0; i < 9; i++)
        cout << a[i] << ",";

 	return 0;
}

 