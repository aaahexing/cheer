/***********************************
Binary Tree Level Order Traversal : https://leetcode.com/problems/binary-tree-level-order-traversal/

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
For example:
Given binary tree {3,9,20,#,#,15,7},
3
/ \
9  20
/  \
15   7
return its level order traversal as:
[
[3],
[9,20],
[15,7]
]
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
vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> vecRes;
	vector<int> vecLevel;
	if (NULL == root) {
		return vecRes;
	}

	queue<TreeNode *> q;
	q.push(root);
	int count = 1;
	int depth = 0;

	while (!q.empty()) {
		TreeNode * front = q.front();
		q.pop();
		count--;
		vecLevel.push_back(front->val);
		if (front->left) {
			q.push(front->left);
		}
		if (front->right) {
			q.push(front->right);
		}

		if (count == 0) {
			count = q.size();
			vecRes.push_back(vecLevel);
			vecLevel.clear();
			depth++;
		}
	}

	return vecRes;
}