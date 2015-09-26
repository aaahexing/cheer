/****************************************
Populating Next Right Pointers in Each Node : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

Given a binary tree 
struct TreeLinkNode {
TreeLinkNode *left;
TreeLinkNode *right;
TreeLinkNode *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.
Note: 
•You may only use constant extra space.
•You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
1
/  \
2    3
/ \  / \
4  5  6  7
After calling your function, the tree should look like:
1 -> NULL
/  \
2 -> 3 -> NULL
/ \  / \
4->5->6->7 -> NULL
**/

//Definition for binary tree with next pointer.
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

//@time complexity: O(n) n is the total number of nodes
//@space complexity: O(n)
//@1A
void connect(TreeLinkNode *root) {
	queue<TreeLinkNode *> q;
	int count = 1;
	if (root == NULL) {
		return ;
	}

	q.push(root);
	while (!q.empty()) {
		TreeLinkNode * front = q.front();
		q.pop();
		count--;
		if (front->left) {
			q.push(front->left);
		}
		if (front->right) {
			q.push(front->right);
		}
		if (count != 0) {
			front->next = q.front();
		} else {
			front->next = NULL;
			count = q.size();
		}
	}
}