/****************************************
Linked List Cycle II : https://leetcode.com/problems/linked-list-cycle-ii/

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Note: Do not modify the linked list.
Follow up:
Can you solve it without using extra space?
**/

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//@time complexity: O(n)
//@space complexity: O(1)
//@2A
//@desc: this can be transformed into the the lastest common node in two linked lists
ListNode *detectCycle(ListNode *head) {
	ListNode * pSlow, * pFast;
	pSlow = pFast = head;
	int step = 0;
	while (pSlow && pFast) {
		pSlow = pSlow->next;
		if (pFast->next == NULL) {
			return NULL;
		}
		pFast = pFast->next->next;
		step++;
		if (pSlow == pFast) {
			break;
		}
	}

	if (pFast == NULL) {
		return NULL;
	}

	pFast = pSlow = head;
	while (step) {
		pFast = pFast->next;
		step--;
	}

	while (pFast != pSlow) {
		pFast = pFast->next;
		pSlow = pSlow->next;
	}

	return pSlow;
}