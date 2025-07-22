#include<bits/stdc++.h>
using namespace std;
int solve(int W,int cost[],int wt[],int n){
    if(n==0) return 0;
    if(wt[n-1]>W){
        return solve(W,cost,wt,n-1);
    }
    int first=0;
    if(wt[n-1]<=W){
        first=solve(W-wt[n-1],cost,wt,n-1)+cost[n-1];
    }
        int second= solve(W,cost,wt,n-1);
    return max(first,second);
}
int main(){
    int n;
    cout<<"Number of tems : ";
    cin>>n;
    int cost[n];
    cout<<"Cost of the items : ";
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    int wt[n];
    cout<<"Weight of items: ";
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    int W;
    cout<<"Maximum capacity of the bag: ";
    cin>>W;
    cout<<solve(W,cost,wt,n);

}