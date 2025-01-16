#include<bits/stdc++.h>
using namespace std;

// Given an array of strings words and an integer k, return the k most frequent strings.

// Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

class Solution {
public:
    struct cmp{
        bool operator()(const pair<int,string>&a,const pair<int,string>&b){
            if(a.first<b.first) return true;
            else if(a.first==b.first && a.second>b.second) return true;
            return false;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mpp;
        for(auto word:words){
            mpp[word]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pq;
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        vector<string>ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};