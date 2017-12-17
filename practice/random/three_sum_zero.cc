#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

//Given an array of integers, return true if there are three numbers that add up to zero (repetition is allowed)


bool three_sum_zero(vector<int>& nums, int val){
    
    for(int i=0; i<nums.size()-2; i++){
        for(int j=i+1; j<nums.size()-1; j++){
            for(int k=j+1; k<nums.size(); k++){
                if(nums.at(i)+nums.at(j)+nums.at(k) == val){
                    cout<<nums.at(i)<<"+"<<nums.at(j)<<"+"<<nums.at(k)<<"="<<val<<endl;
                    return true;
                }
            }
        }
    }
    return false;
}

bool three_sum_zero_method2(vector<int>& nums, int val){

    sort(nums.begin(), nums.end());

    for(int i=0; i<nums.size()-2; i++){
        int l=i+1, r=nums.size()-1;
        while(l<r){
            if(nums.at(i)+nums.at(l)+nums.at(r) == val){
                cout<<nums.at(i)<<"+"<<nums.at(l)<<"+"<<nums.at(r)<<"="<<val<<endl;
                return true;
            }
            else if(nums.at(i)+nums.at(l)+nums.at(r) > val){
                r--;
            }
            else{
                l++;
            }
        }
    }
    return false;
}

int main(void){
    vector<int> nums = {10,-2,-1,3};
    cout<<three_sum_zero(nums, 0)<<endl;
    cout<<three_sum_zero_method2(nums, 0)<<endl;
}
