#include<iostream>
#include<string>
#include<vector>
using namespace std;

    void merge(vector<int>& nums, vector<int> left, vector<int> right){
        int k = 0;
        int l = 0;
        int r = 0;

        while(l<left.size() && r<right.size()){
            if(left.at(l)<right.at(r)){
                nums.at(k)=left.at(l);
                l++;
            }else{
                nums.at(k)=right.at(r);
                r++;
            }
            k++;
        }

        while(l<left.size()){
            nums.at(k)=left.at(l);
            l++;
            k++;
        }

        while(r<right.size()){
            nums.at(k)=right.at(r);
            r++;
            k++;
        }
    }
    void mergeSort(vector<int>& nums){
        if(nums.size() <2)
            return;

        int mid = nums.size()/2;

        vector<int> left(mid), right(nums.size()-mid);

        for(int i=0; i<mid; i++)
            left[i]=nums[i];

        for(int i=mid; i<nums.size(); i++)
            right[i-mid]=nums[i];

        mergeSort(left);
        mergeSort(right);

        merge(nums, left, right);
    }

    void sortColors(int A[], int n) {
        int j = 0, k = n-1;
        for (int i=0; i <= k; i++) {
            if (A[i] == 0)
                swap(A[i], A[j++]);
            else if (A[i] == 2)
                swap(A[i--], A[k--]);
        }
    }

  int main(void){
    int ar[]={2};
    sortColors(ar,1);
    for(auto i : ar) cout<<i<<" ";

    cout<<endl;
  }
    // void sortColors(vector<int>& nums) {
    //     mergeSort(nums);
    // }
