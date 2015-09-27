/*************************************
Symmetric Tree : https://leetcode.com/problems/symmetric-tree/

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
For example, this binary tree is symmetric: 
1
/ \
2   2
/ \ / \
3  4 4  3
But the following is not:
1
/ \
2   2
\   \
3    3
**/

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//-----------------------------------------------first solution------------------------------------------------
//@recursive one
//@time complexity: O(n)
//@space complexity: O(1)
//@2A
bool isSymmetric(TreeNode* root) {
	if (NULL == root) {
		return true;
	}

	return isSymmetric(root->left, root->right);
}

bool isSymmetric(TreeNode * left, TreeNode * right) {
	if (NULL == left && NULL == right) {
		return true;
	}

	if (NULL == left && NULL != right) {
		return false;
	}

	if (NULL == right && NULL != left) {
		return false;
	}

	if (left->val == right->val) {
		return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
	} else {
		return false;
	}
}

//---------------------------------------------------------second solution-------------------------------------------
//@iteratively one
//@time complexity: O(n)
//@space complexity: O(n)
//@1A
bool isSymmetric(TreeNode* root) {
	stack<TreeNode *> s1, s2;
	if (NULL == root) {
		return true;
	}

	s1.push(root->left);
	s2.push(root->right);

	while (!s1.empty() && !s2.empty()) {
		TreeNode * top1 = s1.top();
		TreeNode * top2 = s2.top();
		s1.pop(); s2.pop();

		if (top1 == NULL && top2 == NULL) {
			continue;
		} else if (top1 != NULL && top2 != NULL) {
			if (top1->val != top2->val) {
				return false;
			} else {
				s1.push(top1->left);
				s1.push(top1->right);
				s2.push(top2->right);
				s2.push(top2->left);
			}
		} else {
			return false;
		}
	}

	if (!s1.empty() || !s2.empty()) {
		return false;
	} else {
		return true;
	}
}