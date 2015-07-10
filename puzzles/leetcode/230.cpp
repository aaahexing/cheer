/*******************************************************
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
 You may assume k is always valid, 1 ¡Ü k ¡Ü BST's total elements.

Follow up:
 What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
 If the BST is modified and the kth smallest routine is used frequently, this routine should be optimized.
 To do this, we modify the TreeNode structure and record the nodes this tree includes. Then, the time complexity can be optimized in O(h), h represents the height of the tree.
 *****************************************************/

//general design
//time complexity: O(k)
//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;

	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//time complexity(O(k))
//trial times: one
int kthSmallest(TreeNode* root, int k) {
	int treeNum, kth;
	kthSmallest(root, k, treeNum, kth);
	return kth;
}

bool kthSmallest(TreeNode * root, int k, int & treeNum, int & kth)
{
	int leftTreeNum = 0, rightTreeNum = 0;
	if(root == NULL)
		return false;

	if(kthSmallest(root->left, k, leftTreeNum, kth))
		return true;
	else
	{
		if(leftTreeNum == k-1)
		{
			kth = root->val;
			return true;
		}
		else
		{
			bool res = kthSmallest(root->right, k-leftTreeNum - 1, rightTreeNum, kth);
			treeNum = leftTreeNum + rightTreeNum + 1;
			return res;
		}
	}
}

//second solution
//time complexity: O(h)
//node structure should be modified
//furthermore, we implement the insertion and deletion

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	int nodeNum;
	TreeNode(int x) : val(x), nodeNum(1), left(NULL), right(NULL) {}
};

int countTreeNum(TreeNode * root)
{
	return root == NULL? 0 : root->nodeNum;
}

void updateNodeNum(TreeNode * root)
{
	root->nodeNum = countTreeNum(root->left) + countTreeNum(root->right) + 1;
}

int kthSmallest(TreeNode* root, int k) {
	int leftTreeNum = countTreeNum(root->left);

	if(leftTreeNum == k-1)
		return root->val;
	else if(leftTreeNum < k-1)
		return kthSmallest(root->right, k-leftTreeNum-1);
	else
		return kthSmallest(root->left, k);
}

void insert(TreeNode *& root, int x)
{
	if(root == NULL)
		root = new TreeNode(x);
	else
	{
		if(x < root->val)
			insert(root->left, x);
		else if(x > root->val)
			insert(root->right, x);
		else
			;
	}

	updateNodeNum(root);
}

void remove(TreeNode *& root, int x)
{
	if(root == NULL)
		return;          //doesn't find x, do nothing and return
	else
	{
		if(x < root->val)
			remove(root->left, x);
		else if(x > root->val)
			remove(root->right, x);
		else
		{
			if(root->left && root->right)
			{
				root->val = findMax(root->left)->val;
				remove(root->left, root->val);
			}
			else
				root = root->left ? root->left : root->right;
		}
	}

	updateNodeNum(root);
}

TreeNode * findMax(TreeNode * root)
{
	if(root == NULL)
		return NULL;
	else
		return root->right ? findMax(root->right) : root;
}