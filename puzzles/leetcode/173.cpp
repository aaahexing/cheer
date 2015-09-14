/**************************************
Binary Search Tree Iterator : https://leetcode.com/problems/binary-search-tree-iterator/

Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
Calling next() will return the next smallest number in the BST.
Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree. 
**/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//time complexity: O(1) on average, since every node is pushed once into the stack and poped out once 
//space complexity: O(h), h stands for the height of the tree
class BSTIterator {
private:
    TreeNode * root;
    stack<TreeNode *> s;
public:
    BSTIterator(TreeNode *root) {
        this->root = root;
        TreeNode * cur = root;
        while(cur) {
            s.push(cur);
            cur = cur->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!s.empty());
    }

    /** @return the next smallest number */
    int next() {
        TreeNode * ret = s.top();
        s.pop();
        TreeNode * cur = ret->right;
        while (cur) {
            s.push(cur);
            cur = cur->left;    
        }
        return ret->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */