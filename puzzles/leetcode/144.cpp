/****************************************
Binary Tree Preorder Traversal : https://leetcode.com/problems/binary-tree-preorder-traversal/

Given a binary tree, return the preorder traversal of its nodes' values.
For example:
Given binary tree {1,#,2,3},
1
\
2
/
3
return [1,2,3].
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
vector<int> preorderTraversal(TreeNode* root) {
	vector<int> ret;
	stack<TreeNode *> s;
	if (root == NULL) {
		return ret;
	}
	s.push(root);
	while(!s.empty()) {
		TreeNode * cur = s.top();
		s.pop();
		ret.push_back(cur->val);
		if (cur->right) {
			s.push(cur->right);
		}
		if (cur->left) {
			s.push(cur->left);
		}
	}

	return ret;
}