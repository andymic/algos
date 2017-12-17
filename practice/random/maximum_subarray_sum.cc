#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int maxSubArray(vector<int>& nums, int k){
    unordered_map<int, int> hash;
    int sum = 0;
    int max_len;

    for(int i=0; i<nums.size(); i++){
        sum += nums.at(i);
        
        if(sum == k) max_len = i+1;
        else if(hash.find(sum-k) != hash.end()) max_len = max(max_len, i-hash.at(sum-k));
    
        if(hash.find(sum) == hash.end()) hash[sum]=i;
    }
    return max_len;
}

int main(void){
    vector<int> v={1,-1,5,-2,3};
    cout<<maxSubArray(v,3);
    return 0;
}
