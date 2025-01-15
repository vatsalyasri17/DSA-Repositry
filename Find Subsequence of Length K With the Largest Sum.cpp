#include<bits/stdc++.h>
using namespace std;

// You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        vector<int>ind,ans;
        while(k--){
            pair<int,int>p=pq.top();
            ind.push_back(p.second);
            pq.pop();
        }
        sort(ind.begin(),ind.end());
        for(int i=0;i<ind.size();i++){
            ans.push_back(nums[ind[i]]);
        }
        return ans;
    }
};