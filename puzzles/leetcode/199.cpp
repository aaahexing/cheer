/******************************
Binary Tree Right Side View : https://leetcode.com/problems/binary-tree-right-side-view/

Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
**/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//time complexity: O(n)  n is the total number of nodes in the tree
//space complexity: O(d) d is the depth of the tree
//1A
vector<int> rightSideView(TreeNode* root) {
    vector<int> ret;
    int height = getHeight(root);
    ret.resize(height);
    rightSideView(root, 0, ret);
    return ret;
}
    
//time complexity: O(n) n is the total number of nodes in the tree
int getHeight(TreeNode * root) {
    if (root == NULL) {
        return 0;
    }
    
    int leftHeight = 0, rightHeight = 0;
    if (root->left) {
        leftHeight = getHeight(root->left);
    }
    if (root->right) {
        rightHeight = getHeight(root->right);
    }
    return 1 + max(leftHeight, rightHeight);
}
    
void rightSideView(TreeNode * root, int depth, vector<int> & ret) {
    if (root == NULL) {
        return;
    }
        
    if (root->left) {
        rightSideView(root->left, depth + 1, ret);
    }
        
    ret[depth] = root->val;
    
    if (root->right) {
        rightSideView(root->right, depth + 1, ret);
    }
}
