#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mid=(0+nums.size())/2;
        int cnt=0,i=0,j=mid;
        while(i<mid){
            cnt+=abs(nums[i]-nums[mid]);
            i++;
        }
        while(j<nums.size()){
            cnt+=abs(nums[mid]-nums[j]);
            j++;
        }
        return cnt;

        // Less Time Complexity as nth_element makes middle element to be sorted order in O(1) Complexity.
        int n=nums.size();
        nth_element(nums.begin(),nums.begin()+(n/2),nums.end());
        int steps=0,median=0;
        median=nums[n/2];
        for(int i=0;i<n;i++){
            steps+=abs(median-nums[i]);
        }
        return steps;
    }
};