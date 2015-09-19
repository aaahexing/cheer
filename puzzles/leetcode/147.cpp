/************************************************
Insertion Sort List : https://leetcode.com/problems/insertion-sort-list/

Sort a linked list using insertion sort.
**/

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//@time complexity: O(n^2)
//@space complexity: O(1)
//@stable sort
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}

		int len = getLen(head);
		ListNode * cur = head->next;

		for (int i = 1; i < len; i++) {
			ListNode * before = head;
			ListNode * prev = getPrevCur(head, cur);
			ListNode * tmp = cur->next;
			prev->next = cur->next;
			for (int j = 0; j < i; j++) {
				if (before->val > cur->val && j == 0) {
					cur->next = before;
					head = cur;
					break;
				} else {
					if ((j == i - 1) || (before->val <= cur->val && before->next->val > cur->val)) {
						cur->next = before->next;
						before->next = cur;
						break;
					}
				}
				before = before->next;
			}
			cur = tmp;
		}

		return head;
	}

	int getLen(ListNode * head) {
		if (head == NULL) {
			return 0;
		}

		int len = 0;
		while (head) {
			len++;
			head = head->next;
		}

		return len;
	}

	ListNode * getPrevCur(ListNode * head, ListNode * cur) {
		if (head == cur) {
			return NULL;
		}
		ListNode * prev = head;
		while(prev && prev->next != cur) {
			prev = prev->next;
		}

		return prev;
	}
};