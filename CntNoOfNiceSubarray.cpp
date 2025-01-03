#include<bits/stdc++.h>
using namespace std;


//  Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.
// Return the number of nice sub-arrays.

class Solution {
public:
    int atMost(vector<int>&nums,int k){
        int n=nums.size();
        int i=0,j=0,cnt=0,sum=0;
        while(j<n){
            sum+=(nums[j]%2);
            while(sum>k){
                sum-=(nums[i]%2);
                i++;
            }
            cnt+=(j-i+1);
            j++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
    }
};