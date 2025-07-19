#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* left, * right;
};

class Solution {
  public:
    // void traversal(Node* root,int d,map<int,vector<int>>&mpp){
    //     if(root==NULL){
    //         return;
    //     }
    //     mpp[d].push_back(root->data);
    //     traversal(root->left,d+1,mpp);
    //     traversal(root->right,d,mpp);
    // }
    vector<int> diagonal(Node *root) {
        vector<int>ans;
        // map<int,vector<int>>mpp;
        // int d=0;
        // traversal(root,d,mpp);
        // for(auto it:mpp){
        //     for(auto t:it.second){
        //         ans.push_back(t);
        //     }
        // }
        
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            while(temp){
                ans.push_back(temp->data);
                if(temp->left){
                    q.push(temp->left);
                }
                temp=temp->right;
            }
        }
        return ans;
    }
};