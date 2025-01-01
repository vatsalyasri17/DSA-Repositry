#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        else return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),cmp);
        vector<int>res;
        res.push_back(envelopes[0][1]);
        for(int i=1;i<envelopes.size();i++){
            if(res.back()<envelopes[i][1]){
                res.push_back(envelopes[i][1]);
            }
            else{
                auto ind=lower_bound(res.begin(),res.end(),envelopes[i][1])-res.begin();
                res[ind]=envelopes[i][1];
            }
        }
        return res.size();
    }
};