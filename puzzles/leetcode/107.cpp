/****************************************
Binary Tree Level Order Traversal II  : https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
For example:
Given binary tree {3,9,20,#,#,15,7},
3
/ \
9  20
/  \
15   7
return its bottom-up level order traversal as:
[
[15,7],
[9,20],
[3]
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
//@BFS
//@1A
vector<vector<int>> levelOrderBottom(TreeNode* root) {
	queue<TreeNode *> q;
	int count = 1;
	vector<vector<int>> vecRes;
	vector<int> vecLevel;
	if (root == NULL) {
		return vecRes;
	}

	q.push(root);
	while(!q.empty()) {
		TreeNode * front = q.front();
		q.pop();
		vecLevel.push_back(front->val);
		count--;
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
		}
	}

	reverse(vecRes.begin(), vecRes.end());
	return vecRes;
}