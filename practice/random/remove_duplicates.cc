#include<iostream>
#include<unordered_map>
#include<climits>
#include<vector>

using namespace std;

// Follow up for "Remove Duplicates":
// What if duplicates are allowed at most twice?
//
// For example,
// Given sorted array nums = [1,1,1,2,2,3],
//
// Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

// int removeDuplicates(vector<int>& nums) {
//         unordered_map<int, int> hash;
//         int min = INT_MIN;
//
//         for(int i=0; i<nums.size(); i++){
//             if(hash.find(nums.at(i)) == hash.end())
//                 hash[nums.at(i)]=1;
//             else if(hash.find(nums.at(i)) != hash.end()){
//                 if(hash[nums.at(i)] == 2)
//                     nums.at(i) = min;
//                 else
//                     hash[nums.at(i)]++;
//             }
//         }
//
//         for(vector<int>::iterator it=nums.begin(); it!= nums.end();){
//             if(*it == min)
//                 it = nums.erase(it);
//             else
//                 it++;
//         }
//
//         return nums.size();
//   }

int removeDuplicates(vector<int>& nums){
  int i =0;
  for(int num : nums){
    if(i<2 || num > nums[i-2]){
      nums[i++] = num;
    }
  }
  return i;
}

  int main(){
    vector<int> v = {1,1,1,2,2,3};
    cout<<removeDuplicates(v);
    return 0;
  }
