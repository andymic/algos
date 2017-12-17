#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

bool wordBreak_fail(string s, vector<string>& wordDict) {

    string temp;
    vector<string>::iterator it;
    bool breakable = false;

    for(int i=0; i<s.length(); i++){
        temp+=s[i];

        it = find(wordDict.begin(), wordDict.end(), temp);

        if(it != wordDict.end()){
           cout<<"Found hit : "<<temp<<endl;
           breakable = true;
           temp = "";
        }
    }

    if(breakable == true && temp.length() > 0)
        return false;

    return breakable;
}

bool wordBreak(string s, vector<string>& wordDict){
  vector<bool> vec(s.length()+1, false);
  vector<string>::iterator it;
  vec.at(0) = true;

  for(int i=1; i<=s.length(); i++){
    for(int j=i-1; j>=0; j--){
      if(vec[j]){
        string wd = s.substr(j, i-j);

        it = find(wordDict.begin(), wordDict.end(), wd);
        if(it != wordDict.end()){

          vec[i] = true;
          for(auto i:vec) cout<<i;
          cout<<endl;
          cout<<wd<<endl;
          break;
        }
      }
    }
  }
  return vec[s.size()];
}
int main(void){
  vector<string> vec;
  vec.push_back("leet");
  vec.push_back("code");

  cout<<wordBreak("leetcode", vec);
  return 0;
}
