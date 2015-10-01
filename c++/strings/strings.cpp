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

void SelctionSort(char * s, int len)
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

        swap(s[i], s[min]);
    }
}

void InsertionSort(char * s, int len)
{
    for(int i = 1; i<len; i++)
    {
        int val = s[i];
        int index = i;

        while(index > 0 && s[index - 1] > val)
        {
            s[index] = s[index - 1];
            index--;
        }

        s[index] = val;
    }
}

bool IsAnagram(string a, string b)
{   
    if(a.length() != b.length())
        return false;

    InsertionSort((char *)&a[0], a.length());
    InsertionSort((char *)&b[0], b.length());

    for(int i = 0; i<a.length(); i++)
    {
        if(a[i] != b[i])
            return false;
    }

    return true;
}


int main(void)
{
   cout<<IsAnagram("creative", "reactive");

 	return 0;
}

 