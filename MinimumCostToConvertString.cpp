#include<bits/stdc++.h>
using namespace std;
// You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].

// You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.

// Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.

// Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long arr[26][26];
        for(int i=0;i<26;i++){
            fill(arr[i],arr[i]+26,LLONG_MAX);
            arr[i][i]=0;
        }
        for(int i=0;i<original.size();i++){
            arr[original[i]-'a'][changed[i]-'a']=min(arr[original[i]-'a'][changed[i]-'a'],(long long)cost[i]);
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(arr[i][k]!=LLONG_MAX && arr[k][j]!=LLONG_MAX){
                        arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
                    }
                }
            }
        }
        long long costs=0;
        for(int i=0;i<source.size();i++){
            int val1=source[i]-'a';
            int val2=target[i]-'a';
            if(val1==val2) continue;
            if(arr[val1][val2]==LLONG_MAX){
                return -1;
            }
            else{
                if(costs>LLONG_MAX-arr[val1][val2]){
                    return -1;
                }
                costs+=arr[val1][val2];
            }
        }
        return costs;
    }
};