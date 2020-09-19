#include<iostream>
#include<map>
#include<algorithm>

//string compress aabbcc -> a2b2c2 
//if compress is longer than original, return original

std::string compress(std::string orig)
{
    std::map<char,int> char_map;
    std::map<char,int>::iterator it;

    for(char c : orig)
    {
        it = char_map.find(c);
        if(it == char_map.end())
        {
            char_map[c] = 1;
        }
        else
        {
            it->second++;
        }
    }
    
    std::string tmp;

    for(char c : orig)
    {
        if(tmp.find(c) == std::string::npos)
        {
            tmp += c;
            tmp += std::to_string(char_map[c]);
        }    
    }

    return tmp.length() < orig.length() ? tmp : orig;
}

int main(void)
{
    std::string ar = "aabccccaa";

    std::cout<<"Original: "<<ar<<std::endl;
    std::cout<<"Updated: "<<compress(ar)<<std::endl;

    return 0;
}
