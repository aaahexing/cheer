/**********************************************
Sort List : https://leetcode.com/problems/sort-list/

Sort a linked list in O(n log n) time using constant space complexity.
**/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

//@desc: merge sort
//@time complexity: O(nlogn)
//@space complexity: O(1)
ListNode* sortList(ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return head;
	}

	int len = countListLen(head);
	return sortList(head, len);
}

ListNode * sortList(ListNode * head, int len) {
	if (len == 0) {
		return NULL;
	}
	if (len == 1) {
		return head;
	} 

	ListNode * left, * right;
	int dis = 1;
	left = head;
	while(dis < len/2) {
		head = head->next;
		dis++;
	}

	right = head->next;
	head->next = NULL;
	left = sortList(left, len/2);
	right = sortList(right, len - len/2);
	return mergeList(left, right);
}

ListNode * mergeList(ListNode * left, ListNode * right) {
	ListNode * ret, * cur;

	if (left == NULL) {
		return right;
	}
	if (right == NULL) {
		return left;
	}

	if (left->val < right->val) {
		ret = cur = left;
		left = left->next;
	} else {
		ret = cur = right;
		right = right->next;
	}

	while(left && right) {
		if (left->val < right->val) {
			cur->next = left;
			left = left->next;
		} else {
			cur->next = right;
			right = right->next;
		}
		cur = cur->next;
	}

	if (left == NULL) {
		cur->next = right;
	} else {
		cur->next = left;
	}

	return ret;
}

int countListLen(ListNode * head) {
	int len = 0;
	while (head) {
		len++;
		head = head->next;
	}

	return len;
}