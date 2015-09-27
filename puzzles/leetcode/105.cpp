/**************************************
 Construct Binary Tree from Preorder and Inorder Traversal : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

 Given preorder and inorder traversal of a tree, construct the binary tree.
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
//@1A
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (0 >= preorder.size() || preorder.size() != inorder.size()) {
            return NULL;
        }
        
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
    
    TreeNode * buildTree(vector<int>& preorder, int preStartIdx, int preEndIdx, vector<int>& inorder, int inStartIdx, int inEndIdx) {
        if (preStartIdx > preEndIdx) {
            return NULL;
        }
        
        int rootIdx = inStartIdx;
        for (; rootIdx < inEndIdx; rootIdx++) {
            if (inorder[rootIdx] == preorder[preStartIdx]) {
                break;
            }
        }
        
        TreeNode * root = new TreeNode(preorder[preStartIdx]);
        
        int preLStartIdx = preStartIdx + 1;
        int preLEndIdx = preStartIdx + (rootIdx - inStartIdx);
        int inLStartIdx = inStartIdx;
        int inLEndIdx = rootIdx - 1;
        root->left = buildTree(preorder, preLStartIdx, preLEndIdx, inorder, inLStartIdx, inLEndIdx);
        
        int preRStartIdx = preLEndIdx + 1;
        int preREndIdx = preEndIdx;
        int inRStartIdx = rootIdx + 1;
        int inREndIdx = inEndIdx;
        root->right = buildTree(preorder, preRStartIdx, preREndIdx, inorder, inRStartIdx, inREndIdx);
        
        return root;
    }
};