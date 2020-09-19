#include<iostream>
#include<string.h>
#include<algorithm>

//Replace spaces with %20

bool replaceSpace(char *s, size_t len)
{
    int back_iter = strlen(s)-1; 

    for(int i=len-1; i>=0; back_iter--,i--)
    {
       if(s[i] !=' ')
       {
        std::swap(s[i], s[back_iter]);
       }
       else
       {
        s[back_iter] = '0';
        s[--back_iter] = '2';
        s[--back_iter] = '%';
       }
    }
}

int main(void)
{
    char ar[]="Mr John Smith  test        ";
    
    std::cout<<"Original: "<<ar<<std::endl;
    replaceSpace(&ar[0],19);
    std::cout<<"Updated: ";

    for(char c:ar)
        std::cout<<c;

    std::cout<<std::endl;

    return 0;
}
