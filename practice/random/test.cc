// Example program
#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s) {
        if(s.length() == 0)
            return true;

        string temp;

        for(int i=0; i<s.length(); i++){
            int c = tolower(s[i]);

            if((c>= 48 && c<=57) || c>=97 && c<=122){
                temp+=tolower(s[i]);
            }
        }

        cout<<"temp: "<<temp<<endl;
        cout<<temp.length()<<endl;

        for(int i=0, j=temp.length()-1; i<temp.length()/2; i++, j--){
            if(temp[i] != temp[j]){
              return false;
            }

        }

        return true;
    }

int main()
{
  cout<<isPalindrome("A man, a plan, a canal: Panama")<<endl;
}
