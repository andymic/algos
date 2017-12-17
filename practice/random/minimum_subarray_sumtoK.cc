#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
//int min_sub_array(int s, vector<int> nums) {
//    sort(nums.begin(), nums.end());
//    int curr_min = INT_MAX;
//    for(int i=0; i<nums.size()-1; i++) {
//        int j=i+1;
//        int wd = nums.at(i);
//
//        if(wd == s)
//            return 1;
//
//        while(j<nums.size()) {
//            wd+=nums.at(j);
//            if(wd == s) {
//                curr_min = min(curr_min, j-i);
//                break;
//            }
//            j++;
//        }
//    }
//    return curr_min+1;
//}
bool matchTarget(vector<int> nums, int target) {
    int val=0;
    for(int i:nums) {
        val+=i;
    }
    return val==target;
}
void combination(vector<int> nums, vector<int> buff, int pos, int target, int &curr_min) {
    if(matchTarget(buff, target)) {
        curr_min = min(curr_min, static_cast<int>(buff.size()));
    }
    for(int i=pos; i<nums.size(); i++) {
        buff.push_back(nums.at(i));
        combination(nums, buff, i+1, target, curr_min);
        buff.erase(buff.end()-1);
    }
}
int min_subarray_len(int s, vector<int>& nums) {
    if(nums.size() == 0)
        return 0;
    int curr_min = INT_MAX;
    combination(nums, vector<int>(), 0, s, curr_min);
    if(curr_min == INT_MAX)
        return 0;
    return curr_min;
}
int main(void) {
    vector<int> nums ={2,16,14,15}; //20
   // {1,2,3,4,5};, 11
    cout<<min_subarray_len(20, nums)<<endl;
}
