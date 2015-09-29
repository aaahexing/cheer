/**************************************
Validate Binary Search Tree : https://leetcode.com/problems/validate-binary-search-tree/

Given a binary tree, determine if it is a valid binary search tree (BST). 
Assume a BST is defined as follows: 
•The left subtree of a node contains only nodes with keys less than the node's key.
•The right subtree of a node contains only nodes with keys greater than the node's key.
•Both the left and right subtrees must also be binary search trees.
**/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//@time complexity: O(n)
//@space complexity: O(1)
//@1A
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        int min, max;
        return isValidBST(root, min, max);
    }
    
    bool isValidBST(TreeNode * root, int & min, int & max) {
        if (NULL == root) {
            return true;
        }
        
        if (NULL == root->left && NULL == root->right) {
            min = max = root->val;
            return true;
        }
        
        int leftMin, leftMax;
        int rightMin, rightMax;
        int ret = true;
        
        if (root->left) {
            ret = ret && isValidBST(root->left, leftMin, leftMax);
            ret = ret && (leftMax < root->val);
            if (ret == false) {
                return false;
            }
        }
        
        if (root->right) {
            ret = ret && isValidBST(root->right, rightMin, rightMax);
            ret = ret && (root->val < rightMin);
            if (ret == false) {
                return false;
            }
        }
        
        if (root->left && root->right) {
            min = leftMin;
            max = rightMax;
        } else if (root->left) {
            min = leftMin;
            max = root->val;
        } else {
            min = root->val;
            max = rightMax;
        }
        
        return true;
    }
};