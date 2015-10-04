/*************************************
Remove Duplicates from Sorted List: https://leetcode.com/problems/remove-duplicates-from-sorted-list/

Given a sorted linked list, delete all duplicates such that each element appear only once.
For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
**/

//Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

//@space complexity: O(1)
//@time complexity: O(n)
//@1A
ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL) {
        return NULL;
    }
    ListNode * prev = head;
    ListNode * cur = head->next;
    while(cur) {
        if (prev->val == cur->val) {
            prev->next = cur->next;
            delete cur;
            cur = prev->next;
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
        
    return head;
}
