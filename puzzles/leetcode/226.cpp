/************************
Invert Binary Tree: https://leetcode.com/problems/invert-binary-tree/

Invert a binary tree. 
4
/   \
2     7
/ \   / \
1   3 6   9
to
4
/   \
7     2
/ \   / \
9   6 3   1

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

//@desc: DFS
//@time complexity: O(d) -> d represnets the depth of the tree
//@space compleixty: O(1) 
//1A
TreeNode* invertTree(TreeNode* root) {
	if (root == NULL) {
		return NULL;
	}

	TreeNode * tmp = root->left;
	root->left = root->right;
	root->right = tmp;

	root->left = invertTree(root->left);
	root->right = invertTree(root->right);

	return root;
}
