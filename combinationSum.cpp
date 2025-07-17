#include<bits/stdc++.h>
using namespace std;
void func(int ind,vector<int>arr,vector<int>&temp,int target,vector<vector<int>>&ans){
    if(ind==arr.size()){
        if(target==0){
            ans.push_back(temp);
        }
        return;
    }
    if(arr[ind]<=target){
        temp.push_back(arr[ind]);
        func(ind,arr,temp,target-arr[ind],ans);
        temp.pop_back();
    }
    func(ind+1,arr,temp,target,ans);
}
int main(){
    vector<int>arr={2,3,6,7};
    int target=7;
    vector<int>temp;
    vector<vector<int>>ans;
    func(0,arr,temp,target,ans);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}