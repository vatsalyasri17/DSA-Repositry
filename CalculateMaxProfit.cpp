#include<bits/stdc++.h>
using namespace std;

// BEST TIME TO BUY AND SELL STOCK IV

// You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

// Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
class Solution {
// private:
//     int func(int ind,int buy,int cap,vector<int>&prices,vector<vector<vector<int>>>&dp){
//         if(cap==0) return 0;
//         if(ind==prices.size()) return 0;
//         if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
//         int profit=0;
//         if(buy){
//             profit=max(-prices[ind]+func(ind+1,0,cap,prices,dp),0+func(ind+1,1,cap,prices,dp));
//         }
//         else{
//             profit=max(prices[ind]+func(ind+1,1,cap-1,prices,dp),0+func(ind+1,0,cap,prices,dp));
//         }
//         return dp[ind][buy][cap]=profit;
//     }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>after(2,vector<int>(k+1,0));
        vector<vector<int>>curr(2,vector<int>(k+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
                    int profit=0;
                    if(buy){
                        profit=max(-prices[ind]+after[0][cap],0+after[1][cap]);
                    }
                    else{
                        profit=max(prices[ind]+after[1][cap-1],0+after[0][cap]);
                    }
                    curr[buy][cap]=profit;
                }
            }
            after=curr;
        }
        return after[1][k];
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return func(0,1,k,prices,dp);
    }
};