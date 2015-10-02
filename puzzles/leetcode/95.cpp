/*********************************
Unique Binary Search Trees II: https://leetcode.com/problems/unique-binary-search-trees-ii/

Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
**/

//------------------------------solution 1-------------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(n, 0);
    }

    vector<TreeNode*> generateTrees(int n, int fund) {
    	vector<TreeNode *> retRes;
        if (n == 0) {
            retRes.push_back(NULL);
            return retRes;
        }
        if (n == 1) {
            TreeNode * root = new TreeNode(1 + fund);
            retRes.push_back(root);
            return retRes;
        }

        for (int l = 0; l < n; l++) {
            int r = n - 1 - l;
            vector<TreeNode *> vecLeft = generateTrees(l, fund);
            vector<TreeNode *> vecRight = generateTrees(r, l+fund+1);
            for (int i = 0; i < vecLeft.size(); i++) {
                for (int j = 0; j < vecRight.size(); j++) {
                	TreeNode * root = new TreeNode(l + 1 + fund);
                	root->left = vecLeft[i];
                    root->right = vecRight[j];
                    retRes.push_back(root);
                }
            }
        }

        return retRes;
    }
};

//--------------------------solution 2-------------------------------
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }

    vector<TreeNode*> generateTrees(int left, int right) {
    	vector<TreeNode *> retRes;
        if (left > right) {
            retRes.push_back(NULL);
            return retRes;
        }
        if (left == right) {
            TreeNode * root = new TreeNode(left);
            retRes.push_back(root);
            return retRes;
        }

        for (int l = left - 1; l < right; l++) {
            vector<TreeNode *> vecLeft = generateTrees(left, l);
            vector<TreeNode *> vecRight = generateTrees(l+2, right);
            for (int i = 0; i < vecLeft.size(); i++) {
                for (int j = 0; j < vecRight.size(); j++) {
                    TreeNode * root = new TreeNode(l + 1);
                    root->left = vecLeft[i];
                	root->right = vecRight[j];
                	retRes.push_back(root);
                }
            }
        }

        return retRes;
    }
};
