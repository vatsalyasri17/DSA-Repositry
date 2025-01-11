#include<bits/stdc++.h>
using namespace std;
// You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

// Each minute, a node becomes infected if:

// The node is currently uninfected.
// The node is adjacent to an infected node.
// Return the number of minutes needed for the entire tree to be infected.
class Solution {
public:
    int maxTime=0;
    int dfs(TreeNode* root,int start){
        int depth=0;
        if(root==NULL){
            return depth;
        }
        int leftDepth=dfs(root->left,start);
        int rightDepth=dfs(root->right,start);
        if(root->val==start){
            maxTime=max(leftDepth,rightDepth);
            depth=-1;
        }
        else if(leftDepth>=0 && rightDepth>=0){
            depth=max(leftDepth,rightDepth)+1;
        }
        else{
            maxTime=max(maxTime,abs(leftDepth)+abs(rightDepth));
            depth=min(leftDepth,rightDepth)-1;
        }
        return depth;
    }
    int amountOfTime(TreeNode* root, int start) {
        dfs(root,start);
        return maxTime;
    }
};