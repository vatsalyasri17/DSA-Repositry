#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        Node*curr=head;
        while(curr!=NULL){
            Node*prev=NULL;
            for(int i=0;i<m && curr!=NULL;i++){
                prev=curr;
                curr=curr->next;
            }
            for(int i=0;i<n && curr!=NULL;i++){
                Node*temp=NULL;
                curr=curr->next;
                delete temp;
            }
            prev->next=curr;
        }
        return head;
    }
};