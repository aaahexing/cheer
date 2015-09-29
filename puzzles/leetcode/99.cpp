/********************************************
Recover Binary Search Tree : https://leetcode.com/problems/recover-binary-search-tree/

Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure. 
Note:
 A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 
**/

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//-----------------------------------------solution 1------------------------------------
//@time complexity: O(n)
//@space complexity: O(n)
//@2A: be careful of the if condition of for loop in line 33 and 38
class Solution {
public:
    void recoverTree(TreeNode* root) {
        if (NULL == root) {
            return ;
        }
        
        vector<TreeNode *> vec;
        getTreeNode(root, vec);
        TreeNode * wrong1 = NULL, * wrong2 = NULL;
        for (int i = 0; i < vec.size(); i++) {
            if (i < vec.size() -1 && vec[i]->val > vec[i+1]->val && NULL == wrong1) {
                wrong1 = vec[i];
                continue;
            }
            
            if (i >= 1 && vec[i]->val < vec[i-1]->val) {
                wrong2 = vec[i];
            }
        }
        
        int tmp = wrong1->val;
        wrong1->val = wrong2->val;
        wrong2->val = tmp;
    }
    
    void getTreeNode(TreeNode * root, vector<TreeNode *> & vec) {
        if (NULL == root->left && NULL == root->right) {
            vec.push_back(root);
            return;
        } 
        
        if (root->left) {
            getTreeNode(root->left, vec);
        }
        vec.push_back(root);
        if (root->right) {
            getTreeNode(root->right, vec);
        }
    }
};

//------------------------------------solution 2--------------------------------------