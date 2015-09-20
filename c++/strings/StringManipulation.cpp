#include <iostream>
#include <string>
 
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
 int main(void)
 {
    char s[]="12345648";
    int res=RemoveDuplicates(s);

 	return 0;
 }

 