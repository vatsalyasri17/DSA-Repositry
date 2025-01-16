#include<bits/stdc++.h>
using namespace std;

// Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1));
        vector<int>prev(n+1,0),curr(n+1,0);
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1]==nums2[j-1]){
                    curr[j]=prev[j-1]+1;
                }
                else{
                    curr[j]=0;
                }
                ans=max(ans,curr[j]);
            }
            prev=curr;
        }
        return ans;
    }
};