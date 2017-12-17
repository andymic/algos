#include<iostream>
#include<string>
#include<vector>

using namespace std;

void combine(string s, string buff, int i){
    for(int j=i; j<s.length(); j++){
        buff+=s[j];
        cout<<buff<<endl;
        combine(s, buff, j+1);
        buff=buff.substr(0,buff.size()-1);
    }
}

void combine(vector<int> vec, vector<int> t, vector<vector<int>>& buff, int pos){
    buff.push_back(t);
    for(int i=pos; i<vec.size(); i++){
        t.push_back(vec.at(i));
        combine(vec,t, buff, i+1);
        t.erase(t.end()-1);
    }
}
int main(void){
   string s = "abc";
   string buff;
   //combine(s,buff, 0);
   vector<int> vec = {1,2,3};
   vector<vector<int>> res;

   combine(vec,vector<int>(), res,0);
   for(int i=0; i<res.size(); i++){
        //vector<int> r = buff[i];
        for(auto j: res.at(i))
           cout<<j<<" ";
        cout<<endl;
   }
   return 0;
}
