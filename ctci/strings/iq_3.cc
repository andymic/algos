#include<iostream>
#include<string>
#include<algorithm>

//Find if s1 if permutation of s2

bool isPermutation1(std::string s1, std::string s2)
{
    if(s1.length() != s2.length())
        return false;

    std::sort(s1.begin(), s1.end());
    std::sort(s2.begin(), s2.end());

    return s1 == s2;
}

bool isPermutation2(std::string s1, std::string s2)
{
    if(s1.length() != s2.length())
        return false;

    int ascii[128] = {0};
    int len = s1.length();

    for(int i=0; i<len; i++)
        ascii[(int)s1[i]]++;

    for(int i=0; i<len; i++)
        if(--ascii[(int)s2[i]] < 0) 
            return false;
    
    return true;
}

int main(void)
{
    std::cout<<isPermutation2("abcdefga", "cbaafedg")<<std::endl; 
    return 0;
}
