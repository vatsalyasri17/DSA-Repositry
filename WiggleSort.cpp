//   Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void threeWayPartition(vector<int>&nums,int val){
        int i=0,j=0;
        int n=nums.size()-1;
        while(j<=n){
            if(nums[j]<val){
                swap(nums[i++],nums[j++]);
            }
            else if(nums[j]>val){
                swap(nums[j],nums[n--]);
            }
            else j++;
        }
    }
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        int mid=n/2;
        nth_element(nums.begin(),nums.begin()+mid,nums.end());
        threeWayPartition(nums,nums[mid]);
        int largest=n-1;
        int smallest=(n%2) ? mid : (mid-1);
        vector<int>res(n);
        for(int i=0;i<n;i+=2){
            res[i]=nums[smallest--];
        }
        for(int i=1;i<n;i+=2){
            res[i]=nums[largest--];
        }
        nums=res;
        // vector<int>res(nums);
        // sort(res.begin(),res.end());
        // int i=n-1,j=0,k=i/2+1;
        // while(i>=0){
        //     if(i%2==1){
        //         nums[i]=res[k++];
        //     }
        //     else{
        //         nums[i]=res[j++];
        //     }
        //     i--;
        // }
        // priority_queue<int>pq;
        // for(int i=0;i<n;i++){
        //     pq.push(nums[i]);
        // }
        // int i=1,j=0;
        // while(i<n){
        //     int a=pq.top();
        //     pq.pop();
        //     nums[i]=a;
        //     i+=2;
        // }
        // while(j<n){
        //     int b=pq.top();
        //     pq.pop();
        //     nums[j]=b;
        //     j+=2;
        // }
    }
};