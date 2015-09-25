/********************************************
Binary Tree Maximum Path Sum : https://leetcode.com/problems/binary-tree-maximum-path-sum/

Given a binary tree, find the maximum path sum. 
For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.
For example:
 Given the below binary tree, 
       1
      / \
     2   3
Return 6. 
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

//@time complexity: O(n) n is the total number of nodes
//@space complexity: O(1)
//@2A
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        int totalMaxSum, rootMaxSum;
        getMaxPathSum(root, totalMaxSum, rootMaxSum);
        return totalMaxSum;
    }
    
    void getMaxPathSum(TreeNode * root, int & totalMaxSum, int & rootMaxSum) {
        if (root->left == NULL && root->right == NULL) {
            totalMaxSum = rootMaxSum = root->val;
            return;
        }
        
        int leftTotalMaxSum, leftRootMaxSum, rightTotalMaxSum, rightRootMaxSum;
        totalMaxSum = root->val;
        if (root->left) {
            getMaxPathSum(root->left, leftTotalMaxSum, leftRootMaxSum);
            totalMaxSum += leftRootMaxSum >= 0 ? leftRootMaxSum : 0;
        }
        if (root->right) {
            getMaxPathSum(root->right, rightTotalMaxSum, rightRootMaxSum);
            totalMaxSum += rightRootMaxSum >= 0 ? rightRootMaxSum : 0;
        }
        if (root->left && root->right) {
            int tmp = leftRootMaxSum > rightRootMaxSum ? leftRootMaxSum : rightRootMaxSum;
            rootMaxSum = root->val + (tmp >= 0 ? tmp : 0);
        } else if (root->left) {
            rootMaxSum = root->val + (leftRootMaxSum >= 0 ? leftRootMaxSum : 0);
        } else {
            rootMaxSum = root->val + (rightRootMaxSum >= 0 ? rightRootMaxSum : 0);
        }
        
        if (root->left) {
            totalMaxSum = totalMaxSum > leftTotalMaxSum ? totalMaxSum : leftTotalMaxSum;
        }
        if (root->right) {
            totalMaxSum = totalMaxSum > rightTotalMaxSum ? totalMaxSum : rightTotalMaxSum;
        }
    }
};