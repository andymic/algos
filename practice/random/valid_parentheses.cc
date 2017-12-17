#include<iostream>
using namespace std;

bool isValid(string s) {
       if(s.length() ==0 || s.length()%2 != 0)
            return false;
        stack<char> diff;

        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                diff.push(')');
            }
            else if(s[i]=='{'){
                diff.push('}');
            }
            else if(s[i]=='['){
                diff.push(']');
            }
            else{

                if(diff.size() == 0)
                    return false;

                char t = diff.top();
                if((s[i]==')' && t!=')') || (s[i]=='}' && t!='}') || (s[i]==']' && t!=']'))
                    break;

                diff.pop();
            }
        }

        return (diff.size==0);
    }

int main(void){
  cout<<isValid("()");
  return 0;
}
