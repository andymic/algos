#include<iostream>
#include<set>
//Determine if a string has all unique characters

bool isUnique1(std::string s)
{
    std::set<char> st;

    for(auto& c: s)
        if(!st.insert(c).second)
            return false;

    return true;
    
}

bool isUnique2(std::string s)
{
    //Assuming ASCII
    bool st[256] = {0};

    for(auto& c: s)
        if(st[(int)c])
            return false;
        else
            st[(int)c] = true;
    return true;
}

bool isUnique3(std::string s)
{
    int len = s.length();
    
    for(int i=0; i<=len-1; i++)
    {
        char c = s[i];

        for(int j=i+1; j<=len-1; j++)
            if(s[j] == c)
                return false;
    }
    
    return true;
}

int main(void)
{
    std::cout<<isUnique3("abcdefga")<<std::endl; 
    std::cout<<isUnique3("abcdefg")<<std::endl; 
    return 0;
}
