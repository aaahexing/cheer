/***********************************
Convert Sorted Array to Binary Search Tree : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
**/

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//@DFS
//@devide and conquer
//@1A
TreeNode* sortedArrayToBST(vector<int>& nums) {
	int len = nums.size();
	if (len <= 0) {
		return NULL;
	}
	if (len == 1) {
		return new TreeNode(nums[0]);
	}

	int midIdx = len/2;
	TreeNode * root = new TreeNode(nums[midIdx]);
	vector<int> left(nums.begin(), nums.begin() + midIdx);
	vector<int> right(nums.begin() + midIdx + 1, nums.end());
	root->left = sortedArrayToBST(left);
	root->right = sortedArrayToBST(right);

	return root;
}