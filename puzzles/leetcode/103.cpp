/***************************************
Binary Tree Zigzag Level Order Traversal : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
For example:
Given binary tree {3,9,20,#,#,15,7},
3
/ \
9  20
/  \
15   7
return its zigzag level order traversal as:
[
[3],
[20,9],
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
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
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
			if (depth % 2) {
				reverse(vecLevel.begin(), vecLevel.end());
			}
			vecRes.push_back(vecLevel);
			vecLevel.clear();
			depth++;
		}
	}

	return vecRes;
}