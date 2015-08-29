/********************************
Count Complete Tree Nodes : https://leetcode.com/problems/count-complete-tree-nodes/

Given a complete binary tree, count the number of nodes.
Definition of a complete binary tree from Wikipedia:In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

**/

*
	//@desc: Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//time complexity: O(n) n equals to the total num of the tree
//space complexity: O(1)
int countNodes(TreeNode* root) {
	int maxDepth = getDepth(root);
	if (maxDepth == -1) {
		return 0;
	}

	int maxDepthNumCount = 0;
	bool flag = true;
	countMaxDepthNum(root, maxDepth, maxDepthNumCount, 0, flag);
	return pow(2, maxDepth) -1 + maxDepthNumCount;
}

int getDepth(TreeNode * root) {
	if (root == NULL) {
		return -1;
	}

	int depth = 0;
	while (root->left) {
		depth++;
		root = root->left;
	}

	return depth;
}

void countMaxDepthNum(TreeNode * root, int maxDepth, int & totalNum, int depth, bool & flag) {
	if (depth < maxDepth -1) {
		if (flag) {
			countMaxDepthNum(root->left, maxDepth, totalNum, depth+1, flag);
		}

		if (flag) {
			countMaxDepthNum(root->right, maxDepth, totalNum, depth+1, flag);
		}

		return;
	}

	if (depth == maxDepth -1) {
		if (root->right == NULL) {
			flag = false;
			totalNum += root->left ? 1 : 0;
		} else {
			totalNum += 2;
		}

		return;
	}

	if (depth == maxDepth) {
		totalNum += 1;
	}
}