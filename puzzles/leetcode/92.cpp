/***************************
Reverse Linked List II: https://leetcode.com/problems/reverse-linked-list-ii/

Reverse a linked list from position m to n. Do it in-place and in one-pass.
For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,
return 1->4->3->2->5->NULL.
Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL) {
            return NULL;
        }
        
        pair<ListNode *, ListNode *> p;
        if (m == 1) {
            p = reverse(head, n - m + 1);
            return p.first;
        } else {
            int len = 1;
            ListNode * cur = head;
            ListNode * prev;
            while (len < m) {
                prev = cur;
                cur = cur->next;
                len++;
            }
            p = reverse(cur, n - m + 1);
            prev->next = p.first;
            return head;
        }
    }
    
    //@ret: first->head, second->next; 
    pair<ListNode *, ListNode *> reverse(ListNode * head, int len) {
        if (len == 1) {
            return make_pair(head, head->next);
        }
        
        ListNode * last = head->next;
        pair<ListNode *, ListNode *> p = reverse(head->next, len - 1);
        last->next = head;
        head->next = p.second;
        return p;
    }
};
