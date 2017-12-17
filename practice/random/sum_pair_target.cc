#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>
using namespace std;

bool target_exist(vector<int>& nums, int target){
    
    int len = nums.size();
    unordered_set<int> cache;
    unordered_set<int>::iterator it;

    for(int i=0; i<len; i++){
        it = cache.find(nums.at(i));

        if(it != cache.end())
            return true;

        cache.insert(target - nums.at(i));
    }

    return false;
}

bool target_exist_method2(vector<int>& nums, int target){
    sort(nums.begin(), nums.end());

    int first = 0, last = nums.size()-1;

    while(first<last){
        if(nums.at(first)+nums.at(last) == target)
            return true;
        else if(nums.at(first)+nums.at(last) > target)
            last--;
        else
            first++;
    }
    return false;
}

int main(void){
    vector<int> v = {1,2,4,4};

    cout<<target_exist(v, 8)<<endl;
    cout<<target_exist_method2(v,8)<<endl;
    
}
