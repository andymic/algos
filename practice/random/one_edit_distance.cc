#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

bool isOneEditDistance(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        int c = s.length()-t.length();

        if(s.size() == 0 && t.size() == 0)
            return false;
        else if(abs(c) == 1 ){
          return true;
        }


        int len = (s.size() < t.size())? s.size() : t.size();
        int count =0;
        for(int i=0; i<len; i++){
            if(s[i] != t[i] )
                count++;
        }

        return (count==1);
    }

int main(void){
  cout<<isOneEditDistance("", "A");
}
