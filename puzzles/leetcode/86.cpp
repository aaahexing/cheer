/*********************************
Partition List: https://leetcode.com/problems/partition-list/

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
**/

//Definition for singly-linked list.
struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x) {
    ListNode * insert = NULL;
    ListNode * cur = head, * prev = NULL, * last;
    if (head == NULL) {
        return head;
    }
        
    //get inial insert pos
    if (head->val >= x) {
        insert = NULL;
    } else {
        insert = head;
        while(insert->next && insert->next->val < x) {
            insert = insert->next;
        }
        if (insert->next == NULL) {
            return head;
        }
    }
        
    //update the prev and cur
    if (insert) {
        prev = insert->next;
        cur = prev->next;
    }
    while(cur) {
        if (cur->val >= x) {
            prev = cur;
            cur = cur->next;
        } else {
            prev->next = cur->next;
            last = cur->next;
            if (insert == NULL) {
                cur->next = head;
                insert = head = cur;
            } else {
                cur->next = insert->next;
                insert->next = cur;
                insert = cur;
            }
            cur = last;
        }
    }
        
    return head;
}
