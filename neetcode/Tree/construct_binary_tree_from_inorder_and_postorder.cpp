#include <bits/stdc++.h>
using namespace std;

// First value in preorder will always be root
// we can find the value in inorder, left to that will be part of left subtree
// and right to that will be part of right subtree

class TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if(preorder.size() == 0 && inorder.size() == 0){
        return nullptr;
    }
    
}

int main(){

}