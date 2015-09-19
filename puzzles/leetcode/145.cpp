/***********************************************
Binary Tree Postorder Traversal : https://leetcode.com/problems/binary-tree-postorder-traversal/

Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
1
\
2
/
3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
**/

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//@time complexity: O(n)
//@space complexity: O(n)
//@1A
vector<int> postorderTraversal(TreeNode* root) {
	stack<TreeNode *> s;
	vector<int> ret;
	if (root == NULL) {
		return ret;
	}

	s.push(root);
	while(!s.empty()) {
		TreeNode * cur = s.top();
		if (cur->left == NULL && cur->right == NULL) {
			ret.push_back(cur->val);
			s.pop();
		} else {
			TreeNode * left = cur->left;
			TreeNode * right = cur->right;
			cur->left = cur->right = NULL;
			if (right) {
				s.push(right);
			}
			if (left) {
				s.push(left);
			}
		}
	}

	return ret;
}