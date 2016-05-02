#include<iostream>
#include<string.h>

using namespace std;

int longestValidSubstring(string input)
{
    char l = '(';
    char r = ')';
    int len = input.length();
    int lc = 0, rc = 0;
    
    for(int i = 0; i<len; i++){
        
        if(input[i] == l){
            lc++;
        }
        else{
            rc++;
        }
    }

    if(lc == rc){
        return lc + rc;
    }
    
    if(lc < rc){
        return lc * 2;
    }
    
    return rc * 2;    
}

int main(void){
    //http://www.geeksforgeeks.org/length-of-the-longest-valid-substring/
    // Input : ((()
    // Output : 2
    // Explanation : ()

    // Input: )()())
    // Output : 4
    // Explanation: ()() 

    // Input:  ()(()))))
    // Output: 6
    // Explanation:  ()(()))

    string ar[]={"((()",")()())","()(()))))"};
    
    for(int i = 0; i<3; i++){
        cout<<"LongestValidSubstring is "<<longestValidSubstring(ar[i])<<endl;
    }
    
}


