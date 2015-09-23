/***************************
Sum Root to Leaf Numbers : https://leetcode.com/problems/sum-root-to-leaf-numbers/

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
An example is the root-to-leaf path 1->2->3 which represents the number 123.
Find the total sum of all root-to-leaf numbers.
For example, 
1
/ \
2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13. 
Return the sum = 12 + 13 = 25. 
**/

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//@time complexity: O(n)
//@space complexity: O(l) l is the number of the leaves
//@1A
int sumNumbers(TreeNode* root) {
	if (root == NULL) {
		return 0;
	}

	vector<int> sum;
	int ret = 0;
	sumNumbers(root, sum, 0);
	for (int i = 0; i < sum.size(); i++) {
		ret += sum[i];
	}

	return ret;
}

void sumNumbers(TreeNode * root, vector<int> & sum, int tmpSum) {
	tmpSum = tmpSum * 10 + root->val;
	if (root->left == NULL && root->right == NULL) {
		sum.push_back(tmpSum);
	}

	if (root->left) {
		sumNumbers(root->left, sum, tmpSum);
	}

	if (root->right) {
		sumNumbers(root->right, sum, tmpSum);
	}
}