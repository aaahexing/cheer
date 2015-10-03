/**********************************
Binary Tree Inorder Traversal: https://leetcode.com/problems/binary-tree-inorder-traversal/

Given a binary tree, return the inorder traversal of its nodes' values.
For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].
**/

//@time complexity: O(n)
//@space complexity: O(n)
//@1A
//Definition for a binary tree node.
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode *> s;
    vector<int> ret;
    if (root == NULL) {
        return ret;
    }
    s.push(root);
    while (!s.empty()) {
        TreeNode * top = s.top();
        if (top->left) {
            TreeNode * left = top->left;
            top->left = NULL;
            s.push(left);
        } else {
            s.pop();
            ret.push_back(top->val);
            if (top->right) {
                s.push(top->right);
            }
        }
    }
        
    return ret;
}
