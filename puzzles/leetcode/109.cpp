/**************************************
Convert Sorted List to Binary Search Tree : https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
**/

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//@1A
//@devide and conquer
//@DFS
class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (head == NULL) {
			return NULL;
		}

		int len = getListLen(head);
		int midIdx = len/2;
		ListNode * leftLastNode = head;
		ListNode * rootListNode;

		if (len == 1) {
			return new TreeNode(head->val);
		}

		int step = 1;
		while(step < midIdx) {
			leftLastNode = leftLastNode->next;
			step++;
		}

		rootListNode = leftLastNode->next;
		leftLastNode->next = NULL;
		TreeNode * root = new TreeNode(rootListNode->val);
		root->left = sortedListToBST(head);
		root->right = sortedListToBST(rootListNode->next);

		return root;
	}

	int getListLen(ListNode * head) {
		int len = 0;
		while (head) {
			len++;
			head = head->next;
		}

		return len;
	}
}; 