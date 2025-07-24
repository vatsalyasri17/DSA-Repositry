#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
void buildTree(vector<int>& preorder, int& i, int min, int max) {
    if (i >= preorder.size()) return;
    int val = preorder[i];
    if (val < min || val > max) return;
    Node* node = new Node(val);
    i++;
    buildTree(preorder, i, min, val);
    buildTree(preorder, i, val, max);
}
int main() {
    vector<int> preorder = {10, 5, 1, 7, 40, 50};
    int min = INT_MIN, max = INT_MAX, i= 0;
    buildTree(preorder, i, min, max);
    return i== preorder.size() ? 0 : 1;

}