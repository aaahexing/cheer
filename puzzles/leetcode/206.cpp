/******************
Reverse Linked List :  https://leetcode.com/problems/reverse-linked-list/

Reverse a singly linked list.
**/


//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//time complexity: O(n)
//space complexity: O(n)
//1A
ListNode* reverseList(ListNode* head) {
	if (head == NULL) {
		return NULL;
	}

	ListNode * pHead;
	ListNode * pNow;

	stack<ListNode *> s;
	pNow = head;
	while (pNow) {
		s.push(pNow);
		pNow = pNow->next;
	}

	pNow = pHead = s.top();
	s.pop();
	while (!s.empty()) {
		pNow->next = s.top();
		s.pop();
		pNow = pNow->next;
	}
	pNow->next = NULL;

	return pHead;
}

//recursive one
ListNode* reverseList(ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	ListNode * lastNode = head->next;
	ListNode * retNode = reverseList(lastNode);
	head->next = NULL;
	lastNode->next = head;

	return retNode;
}

//iteratively one
ListNode* reverseList(ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}
	ListNode * p = head;
	ListNode * q = head->next;
	head->next = NULL;

	while (q) {
		ListNode * tmp = q->next;
		q->next = p;
		p = q;
		q = tmp;
	}

	return p;
}