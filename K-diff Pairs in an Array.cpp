#include<bits/stdc++.h>
using namespace std;

// Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

// A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

// 0 <= i, j < nums.length
// i != j
// |nums[i] - nums[j]| == k
// Notice that |val| denotes the absolute value of val.

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(auto it:nums) mpp[it]++;
        int ans=0;
        for(auto it:mpp){
            if(k==0){
                if(it.second>1){
                    ans++;
                }
            }
            else if(mpp.find(it.first+k)!=mpp.end()){
                ans++;
            }
        }
        return ans;
        // sort(nums.begin(),nums.end());
        // set<pair<int,int>>st;
        // int i=0,j=1;
        // while(j<nums.size()){
        //     int diff=nums[j]-nums[i];
        //     if(diff==k){
        //         st.insert({nums[i],nums[j]});
        //         i++;
        //         j++;
        //     }
        //     else if(diff>k){
        //         i++;
        //     }
        //     else j++;
        //     if(i==j) j++;
        // }
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         if(abs(nums[i]-nums[j])==k){
        //             st.insert({nums[i],nums[j]});
        //         }
        //     }
        // }
        // return st.size();
    }
};