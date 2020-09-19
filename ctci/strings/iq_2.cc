#include<iostream>
#include<string.h>
#include<algorithm>

//Reverse a c-style string

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverse1(char *s)
{
    int len =0;

    while(s[len] != '\0')
        len++;

    for(int i=0, j=len; i<len/2; i++,j--)
    {
        swap(s+i,s+j);
    }

}

void reverse2(char *s)
{
    int len = strlen(s);

    for(int i=0, j=len-1; i<len/2; i++,j--)
    {
        std::swap(s[i], s[j]);
    }
}

void reverse3(char *s)
{
    int len = strlen(s);

    for(int i=0; i<len/2; i++)
    {
        char temp = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = temp;
    }
}

void reverse4(char *s)
{
    int len = strlen(s);

    for(int i=0, j=len; i<len/2; i++,j--)
    {
        std::reverse(s+i, s+j);
    }
}

void reverse5(char *s)
{
    char *end = s;
    char tmp;

    while(*end)
        end++;

    end--;

    while(s < end)
    {
        tmp = *s;
        *s = *end;
        *end-- = tmp;
    }
}

int main(void)
{
    char s[] = "abcdefg";
    std::cout<<"Original: "<<s<<std::endl;
    reverse5(&s[0]);

    std::cout<<"Reversed: ";
    size_t len = sizeof(s)/sizeof(*s);
    for(int i =0; i<len; i++)
        std::cout<<s[i];
    std::cout<<std::endl;

    return 0;
}
