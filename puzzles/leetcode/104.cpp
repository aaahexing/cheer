/*********************************
Maximum Depth of Binary Tree : https://leetcode.com/problems/maximum-depth-of-binary-tree/

Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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
int maxDepth(TreeNode* root) {
	if (NULL == root) {
		return 0;
	}

	queue<TreeNode *> q;
	q.push(root);
	int count = 1;
	int depth = 1;
	while(!q.empty()) {
		if (count == 0) {
			count = q.size();
			depth++;
		}

		TreeNode * front = q.front();
		q.pop();
		count--;
		if (front->left) {
			q.push(front->left);
		}
		if (front->right) {
			q.push(front->right);
		}
	}

	return depth;
}