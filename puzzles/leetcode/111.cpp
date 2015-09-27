/**************************
Minimum Depth of Binary Tree : https://leetcode.com/problems/minimum-depth-of-binary-tree/

Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
**/

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//@BFS
//@1A
int minDepth(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}
	int depth = 1;
	int count = 1;
	queue<TreeNode *> q;
	q.push(root);

	while (!q.empty()) {
		TreeNode * front = q.front();
		q.pop();
		count--;
		if (NULL == front->left && NULL == front->right) {
			break;
		}
		if (front->left) {
			q.push(front->left);
		}
		if (front->right) {
			q.push(front->right);
		}
		if (count == 0) {
			count = q.size();
			depth++;
		}
	}

	return depth;
}