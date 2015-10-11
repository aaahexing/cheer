/***********************************
Rotate List : https://leetcode.com/problems/rotate-list/

Given a list, rotate the list to the right by k places, where k is non-negative.
For example:
 Given 1->2->3->4->5->NULL and k = 2,
 return 4->5->1->2->3->NULL.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) {
            return NULL;
        }
        
        int len = getLen(head);
        k = k % len;
        if (k == 0 || len == 0) {
            return head;
        }
        ListNode * newHead = head;
        ListNode * tail = NULL;
        int step = len - k;
        while (step > 0) {
            tail = newHead;
            newHead = newHead->next;
            step--;
        }
        tail->next = NULL;
        tail = newHead;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = head;
        
        return newHead;
    }
    
    int getLen(ListNode * head) {
        if (head == NULL) {
            return 0;
        }
        
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        
        return len;
    }
};