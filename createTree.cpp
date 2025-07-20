#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};
Node* createTree(){
    cout<<"Enter the value of node ";
    int data;
    cin>>data;
    if(data==-1) return NULL;
    Node* root = new Node(data);
    cout<<"left of the node: "<<root->data<<endl;
    root->left=createTree();
    cout<<"right of the node: "<<root->data<<endl;
    root->right=createTree();
    return root;
}
void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    Node* root=createTree();
    inorder(root);
}