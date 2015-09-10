/*****************
Remove Linked List Elements : https://leetcode.com/problems/remove-linked-list-elements/

Remove all elements from a linked list of integers that have value val.
Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5 
**/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

//time complexity: O(n)
//1A
ListNode* removeElements(ListNode* head, int val) {
	if (head == NULL) {
		return head;
	}

	if (head->val == val) {
		ListNode * cur = head;
		delete head;
		return removeElements(cur->next, val);
	} else {
		head->next = removeElements(head->next, val);
		return head;
	}
}