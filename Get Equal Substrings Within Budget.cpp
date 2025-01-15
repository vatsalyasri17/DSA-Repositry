#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int start=0;
        int n=s.size();
        int current_cost=0,maxLen=0;
        for(int end=0;end<n;end++){
            current_cost+=abs(s[end]-t[end]);
            while(current_cost>maxCost){
                current_cost-=abs(s[start]-t[start]);
                start++;
            }
            maxLen=max(maxLen,end-start+1);
        }
        return maxLen;
    }
};