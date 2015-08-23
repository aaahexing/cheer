/********
https://leetcode.com/problems/binary-tree-paths/
Given a binary tree, return all root-to-leaf paths.
**/


// Definition for a binary tree node.
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//@desc: DFS
//@time complexity: O(n)
//@space compleixty: O(1)
vector<string> binaryTreePaths(TreeNode* root) {
  vector<string> res;
  res.clear();
  string path;
  binaryTreePaths(root, res, path);
  return res;
}
    
void binaryTreePaths(TreeNode * root, vector<string> & res, string path) {
    if (root == NULL) {
        return;
    }
        
    stringstream ss;
    string val;
    ss<<root->val;
    ss>>val;
        
    if (root->left == NULL && root->right == NULL) {
        path = path + val;
        res.push_back(path);
        return;
    }
        
        
    path = path + val + "->";
    if (root->left) {
        binaryTreePaths(root->left, res, path);
    }
    if(root->right) {
        binaryTreePaths(root->right, res, path);
    }
}
