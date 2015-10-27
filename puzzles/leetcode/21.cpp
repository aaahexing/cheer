/********************************
Merge Two Sorted Lists : https://leetcode.com/problems/merge-two-sorted-lists/

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
**/

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//@time complexity: O(m + n), m , n are the length of l1 and l2, respectively
//@space complexity: O(1)
//@3A, condition of l1 or l2 == null is not considered, cur was not initialized as NULL, -> caused the failures
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode * head = NULL, * cur = NULL;
        if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        }
        while (l1 && l2) {
            ListNode * tmp;
            if (l1->val < l2->val) {
                tmp = l1;
                l1 = l1->next;
            } else {
                tmp = l2;
                l2 = l2->next;
            }
            if (cur) {
                cur->next = tmp;
                cur = cur->next;
            } else {
                head = cur = tmp;
            }
        }
        
        if (l1) {
            cur->next = l1;
        } else if (l2) {
            cur->next = l2;
        }
        return head;
    }
};