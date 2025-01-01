#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getWin(int n,int k){
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=(ans+k)%i;
        }
        return ans;
    }
    int findTheWinner(int n, int k) {
        return getWin(n,k)+1;
        // vector<int>circle;
        // for(int i=1;i<=n;i++){
        //     circle.push_back(i);
        // }
        // int curr_ind=0;
        // while(circle.size()>1){
        //     int nextRemove=(curr_ind+k-1)%circle.size();
        //     circle.erase(circle.begin()+nextRemove);
        //     curr_ind=nextRemove;
        // }
        // return circle[0];
    }
};