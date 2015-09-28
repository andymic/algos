#include <iostream>
#include <string.h>
 
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
 int main(void)
 {
    char s[]="ABC";
    Permutate(s, 0, 3);

 	return 0;
 }

 