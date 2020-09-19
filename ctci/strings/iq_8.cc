#include<iostream>
#include<algorithm>


bool isRotation(std::string &s1, std::string &s2)
{
    bool ar[256] = {false};

    for(char c : s1)
        ar[(int)c] = true;
    
    for(char c : s2)
        if(!ar[(int)c) return false;

    return true;
}

int main()
{
    std::string a = "waterbottle";
    std::string b = "erwat";

    std::cout<<isRotation(a,b)<<std::endl;
    return 0;
}
