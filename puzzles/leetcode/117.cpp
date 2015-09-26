/**********************************
Populating Next Right Pointers in Each Node II : https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

Follow up for problem "Populating Next Right Pointers in Each Node".
What if the given tree could be any binary tree? Would your previous solution still work? YES!!!!!
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