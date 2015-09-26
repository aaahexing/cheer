/******************************
Path Sum II : https://leetcode.com/problems/path-sum-ii/

Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum. 
For example:
Given the below binary tree and sum = 22,
5
/ \
4   8
/   / \
11  13  4
/  \    / \
7    2  5   1
return
[
[5,4,11,2],
[5,8,4,5]
]
**/

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//@time complexity: O(n)
//@space complexity: O(1)
//@1A
vector<vector<int>> pathSum(TreeNode* root, int sum) {
	vector<vector<int>> vecPath;
	vector<int> path;
	pathSum(root, sum, vecPath, path);
	return vecPath;
}

void pathSum(TreeNode * root, int sum, vector<vector<int>> & vecPath, vector<int> path) {
	if (NULL == root) {
		return ;
	}
	if (NULL == root->left && NULL == root->right) {
		if (root->val == sum) {
			path.push_back(root->val);
			vecPath.push_back(path);
		}
		return;
	}

	path.push_back(root->val);
	pathSum(root->left, sum - root->val, vecPath, path);
	pathSum(root->right, sum - root->val, vecPath, path);
}