/***********************************
Balanced Binary Tree : https://leetcode.com/problems/balanced-binary-tree/

Given a binary tree, determine if it is height-balanced. 
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 
**/

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//@DFS
//@1A
bool isBalanced(TreeNode* root) {
	if (root == NULL) {
		return true;
	}

	if (isBalanced(root->left) && isBalanced(root->right) && abs(getHeight(root->left) - getHeight(root->right)) <= 1) {
		return true;
	} else {
		return false;
	}
}

int getHeight(TreeNode * root) {
	if (root == NULL) {
		return 0;
	} 
	if (NULL == root->left && NULL == root->right) {
		return 1;
	}

	return max(getHeight(root->left), getHeight(root->right)) + 1;
}