#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int> > v(1, vector<int>());

    sort(nums.begin(), nums.end());

    for(int i=0; i<nums.size(); i++){
        int size = v.size();
        for(int j=0; j<size; j++){
            v.push_back(v[j]);
            v.back().push_back(nums.at(i));
        }
    }
    return v;
}

int main(void){
    vector<int> v = {1,2,3};
    
    vector<vector<int>> res = subsets(v);

    for(int i=0; i<res.size(); i++){
        for(auto i: res.at(i))
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
