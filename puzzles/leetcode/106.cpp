/****************************************
Construct Binary Tree from Inorder and Postorder Traversal : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

Given inorder and postorder traversal of a tree, construct the binary tree.
Note:
 You may assume that duplicates do not exist in the tree. 
**/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//@time complexity: O(n)
//@space complexity: O(1)
//@2A
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (0 == inorder.size() || inorder.size() != postorder.size()) {
            return NULL;
        }
        
        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
    
    TreeNode * buildTree(vector<int>& inorder, int inorderStartIdx, int inorderEndIdx, vector<int>& postorder, int postorderStartIdx, int postorderEndIdx) {
        if (inorderStartIdx > inorderEndIdx) {
            return NULL;
        }
        
        TreeNode * root = new TreeNode(postorder[postorderEndIdx]);
        int rootIdx = inorderStartIdx;
        for (; rootIdx <= inorderEndIdx; rootIdx++) {
            if (inorder[rootIdx] == postorder[postorderEndIdx]) {
                break;
            } 
        }
        
        int inorderLStartIdx = inorderStartIdx;
        int inorderLEndIdx = rootIdx - 1;
        int postorderLStartIdx = postorderStartIdx;
        int postorderLEndIdx = postorderStartIdx + (rootIdx - 1 - inorderStartIdx);
        root->left = buildTree(inorder, inorderLStartIdx, inorderLEndIdx, postorder, postorderLStartIdx, postorderLEndIdx);
        
        int inorderRStartIdx = rootIdx + 1;
        int inorderREndIdx = inorderEndIdx;
        int postorderRStartIdx = postorderLEndIdx + 1;
        int postorderREndIdx = postorderEndIdx - 1;
        root->right = buildTree(inorder, inorderRStartIdx, inorderREndIdx, postorder, postorderRStartIdx, postorderREndIdx);
        
        return root;
    }
};