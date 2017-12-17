#include <iostream>
#include <stack>
#include <string.h>

/** The Algorithm Design Manual P.110
A common problem for compilers and text editors is determining whether the
parentheses in a string are balanced and properly nested. For example, the string
((())())() contains properly nested pairs of parentheses, which the strings )()( and
()) do not. Give an algorithm that returns true if a string contains properly nested
and balanced parentheses, and false if otherwise. For full credit, identify the position
of the first offending parenthesis if the string is not properly nested and balanced.
*/

struct Balanced{
    bool balanced = false;
    int index = -1;
};

Balanced get_offending_parenthese(std::string s){
    int len = s.length();
    char open = '(', close = ')';
    Balanced p;

    if(len == 0)
        return p;
    else if(s[0] != open)
        return p = {false, 0};
    else{
        std::stack<char> paren;
        for(int i=0; i<len; i++){

            if(paren.size() == 0 && s[i] == close){
                p.balanced = false;
                p.index = i;
                return p;                       
            }

            if(s[i]== open){
                paren.push(s[i]);
            }
            else if(s[i] == close){
                paren.pop();
            }
        }
    }
    return p = {true, -1};
}

bool parentheses_match(std::string s){
    int len = s.length();
    char init = '(';
    
    if(len == 0 || (len % 2) != 0 || s[0]!= init)
        return false;

    std::stack<char> paren;

    for(int i= 0; i<len; i++){
        if(s[i]==init)
            paren.push(init);
        else
            paren.pop();
    }
    return (paren.size()==0)? true: false;
}

int main(void){
    std::string s[]={"((())())()",")()(","())"};
    int len = sizeof(s)/sizeof(std::string);

    for(int i=0; i<len; i++){
        std::cout<<"Is '"<<s[i]<<"' balanced?: "<<((parentheses_match(s[i])==true) ? "true": "false")<<std::endl; 
    }

    std::cout<<std::endl;

    for(int i=0; i<len; i++){
        std::cout<<"Offending Index for '"<<s[i]<<"' balanced?: "<<std::endl;
        Balanced p = get_offending_parenthese(s[i]);
        std::cout<<"{balanced:"<<p.balanced<<", index:"<<p.index<<"}"<<std::endl;
    } 
}
