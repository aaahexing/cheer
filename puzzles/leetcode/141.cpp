/********************************
Linked List Cycle: https://leetcode.com/problems/linked-list-cycle/

Given a linked list, determine if it has a cycle in it.
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
bool hasCycle(ListNode *head) {
	ListNode * pSlow;
	ListNode * pFast;
	if (head == NULL || head->next == NULL) {
		return false;
	}
	pSlow = pFast = head;
	while(pSlow && pFast) {
		pSlow = pSlow->next;
		if (pFast->next) {
			pFast = pFast->next->next;
		} else {
			break;
		}
		if (pSlow == pFast) {
			return true;
		}
	}

	return false;
}