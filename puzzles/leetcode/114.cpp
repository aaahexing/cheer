/***************************************
Flatten Binary Tree to Linked List : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

Given a binary tree, flatten it to a linked list in-place. 
For example,
 Given 
         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
**/

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void flatten(TreeNode* root) {
	TreeNode * last = NULL;
	flatten(root, last);
}

//@time complexity: O(n)
//@space complexity: O(n)
void flatten(TreeNode * root, TreeNode * & last) {
	if (root == NULL) {
		return;
	}
	if (root->left == NULL && root->right == NULL) {
		last = root;
		return;
	}

	TreeNode * right = root->right;
	TreeNode * leftLast = root;
	if (root->left) {
		flatten(root->left, leftLast);
		root->right = root->left;
	}
	root->left = NULL;

	if (right) {
		flatten(right, last);
		leftLast->right = right;
	} else {
		last = leftLast;
	}
}