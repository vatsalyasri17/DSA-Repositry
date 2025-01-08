#include<bits/stdc++.h>
using namespace std;

// You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:

// The length of the subarray is k, and
// All the elements of the subarray are distinct.
// Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        long long sum=0,maxSum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
            mpp[nums[i]]++;
        }
        if(mpp.size()==k) maxSum=sum;
        for(int i=k;i<nums.size();i++){
            sum+=nums[i];
            mpp[nums[i]]++;
            sum-=nums[i-k];
            mpp[nums[i-k]]--;
            if(mpp[nums[i-k]]==0){
                mpp.erase(nums[i-k]);
            }
            if(mpp.size()==k){
                maxSum=max(maxSum,sum);
            }
        }
        return maxSum;
    }
};