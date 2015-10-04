/*****************************
Remove Duplicates from Sorted List II: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
**/

//Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

//@time complexity: O(n)
//@space complexity: O(1)
ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode * tmp = new ListNode(INT_MIN);
    tmp->next = head;
    ListNode * prev = tmp, * cur = head, * dup = NULL;
    while (cur) {
        if (dup) {
            if (cur->val == dup->val) {
                dup->next = cur->next;
                delete cur;
                cur = dup->next;
            } else {
                prev->next = dup->next;
                delete dup;
                dup = NULL;
            }
        } else {
            if (cur->next) {
                if (cur->val == cur->next->val) {
                    ListNode * tmp = cur->next;
                    cur->next = cur->next->next;
                    delete tmp;
                    dup = cur;
                    cur = cur->next;
                } else {
                    prev = cur;
                    cur = cur->next;
                }
            } else {
                cur = cur->next;
            }
        }
    }
    if (dup) {
        prev->next = dup->next;
        delete dup;
        dup == NULL;
    }
        
    head = tmp->next;
    delete tmp;
    return head;
}
