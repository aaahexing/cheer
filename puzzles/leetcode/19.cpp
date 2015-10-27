/******************************
Remove Nth Node From End of List : https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Given a linked list, remove the nth node from the end of list and return its head.
For example,
   Given linked list: 1->2->3->4->5, and n = 2.
   After removing the second node from the end, the linked list becomes 1->2->3->5.
**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//--------------------------------------------------------first solution---------------------------------------
//@time complexity: O(n), two pass
//@space complexity: O(1)
//@1A
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = getLen(head);
        int pos = len - n;
        if (pos == 0) {
            return head->next;
        }
        ListNode * prev = head;
        int prevIdx = 0;
        while (prevIdx < pos - 1) {
            prev = prev->next;
            prevIdx++;
        }
        ListNode * removeNode = prev->next;
        prev->next = removeNode->next;
        delete removeNode;
        return head;
    }
    
    int getLen(ListNode * head) {
        if (head == NULL) {
            return 0;
        }
        ListNode * cur = head;
        int len = 1;
        while (cur->next) {
            len++;
            cur = cur->next;
        }
        return len;
    }
};

//-----------------------------------------------second solution -----------------------------------
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n == 0) {
            return head;
        }
        ListNode * fast = head;
        ListNode * slow = head;
        ListNode * prev = NULL;
        for (int i = 1; i < n; i++) {
            fast = fast->next;
        }
        while (fast->next) {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        if (prev) {
            prev->next = slow->next;
        } else {
            head = slow->next;
        }
        delete slow;
        
        return head;
    }
};