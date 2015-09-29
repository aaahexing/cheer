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
//@time complexity: can't be count exactly
//@space complexity: O(1)
class Solution {
public:
    void recoverTree(TreeNode* root) {
        if (NULL == root) {
            return;
        }
        
        if (root->left != NULL && root->right == NULL) {
            pair<TreeNode *, TreeNode *> L = getMinMax(root->left);
            if (L.second->val > root->val) {
                swap(L.second->val, root->val);
            } else {
                recoverTree(root->left);
            }
        } else if (root->left == NULL && root->right != NULL) {
            pair<TreeNode *, TreeNode *> R = getMinMax(root->right);
            if (R.first->val < root->val) {
                swap(R.first->val, root->val);
            } else {
                recoverTree(root->right);
            }
        } else if (root->left != NULL && root->right != NULL) {
            pair<TreeNode *, TreeNode *> L = getMinMax(root->left);
            pair<TreeNode *, TreeNode *> R = getMinMax(root->right);
            if (L.second->val > root->val && R.first->val > root->val) {
                swap(L.second->val, root->val);
            } else if (L.second->val > root->val && R.first->val < root->val) {
                swap(L.second->val, R.first->val);
            } else if (L.second->val < root->val && R.first->val < root->val) {
                swap(R.first->val, root->val);
            } else {
                recoverTree(root->left);
                recoverTree(root->right);
            }
        }
    }
    
    pair<TreeNode *, TreeNode *> getMinMax(TreeNode * root) {
        pair<TreeNode *, TreeNode *> ret = make_pair(root, root);
        if (root->left) {
            pair<TreeNode *, TreeNode *> L = getMinMax(root->left);
            if (L.first->val < ret.first->val) {
                ret.first = L.first;
            }
            if (L.second->val > ret.second->val) {
                ret.second = L.second;
            }
        }
        if (root->right) {
            pair<TreeNode *, TreeNode *> R = getMinMax(root->right);
            if (R.first->val < ret.first->val) {
                ret.first = R.first;
            }
            if (R.second->val > ret.second->val) {
                ret.second = R.second;
            }
        }
    }
};