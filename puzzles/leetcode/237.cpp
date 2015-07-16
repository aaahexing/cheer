/*********************************************
Delete Node in a Linked List: https://leetcode.com/problems/delete-node-in-a-linked-list/
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node. 
Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function. 
**********************************************/


//time complexity: O(1)
//space complexity: O(1)
//Once the deleted node is the tail, O(n) time would be consumed. In our code, we exclude this situation.
void deleteNode(ListNode* node) {
	if(node == NULL)
		return;

	node->val = node->next->val;
	ListNode * temp = node->next;
	node->next = node->next->next;
	delete temp;
}