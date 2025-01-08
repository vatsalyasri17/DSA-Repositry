#include<bits/stdc++.h>
using namespace std;
// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int>freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<s.size();i++){
            if(freq[s[i]-'a']==1){
                return i;
            }
        }
        return -1;
        // unordered_map<int,int>mpp;
        // for(int i=0;i<s.size();i++){
        //     mpp[s[i]]++;
        // }
        // char ch;
        // bool f=false;
        // int ind=-1;
        // if(mpp.size()==s.size()) return 0;
        // for(auto it:mpp){
        //     if(it.second==1){
        //         ch=it.first;
        //         f=true;
        //     }
        // }
        // if(f==false) return -1;
        // for(int i=0;i<s.size();i++){
        //     if(ch==s[i]){
        //         ind=i;
        //     }
        // }
        // return ind;
    }
};