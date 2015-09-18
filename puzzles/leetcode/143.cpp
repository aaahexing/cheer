/**************************************
Reorder List : https://leetcode.com/problems/reorder-list/

Given a singly linked list L: L0��L1������Ln-1��Ln,
reorder it to: L0��Ln��L1��Ln-1��L2��Ln-2���� 
You must do this in-place without altering the nodes' values.
For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}. 
**/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	void reorderList(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return ;
		}

		ListNode * left, * right;
		split(head, left, right);
		right = reverse(right);
		head = merge(left, right);
	}

	void split(ListNode * & head, ListNode * & left, ListNode * & right) {
		int len = getListLen(head);
		int dis = 1;

		left = head;
		while(++dis <= len/2) {
			head = head->next;
		}
		right = head->next;
		head->next = NULL;
	}

	int getListLen(ListNode * head) {
		int len = 0;
		while(head) {
			len++;
			head = head->next;
		}

		return len;
	}

	ListNode * merge(ListNode * left, ListNode * right) {
		ListNode * head = left;
		ListNode * tail = NULL;

		while (left && right) {
			ListNode * tmp = left->next;

			if (tail) {
				tail->next = left;
			}
			left->next = right;
			tail = right;
			left = tmp;
			right = right->next;
		}

		if (left) {
			tail->next = left;
		}
		if (right) {
			tail->next = right;
		}
		return head;
	}

	ListNode * reverse(ListNode * head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}

		ListNode * tail = head->next;
		ListNode * cur =  head;
		head = reverse(head->next);
		tail->next = cur;
		cur->next = NULL;

		return head;
	}
};

