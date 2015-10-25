/*****************************************8
Reverse Nodes in k-Group : https://leetcode.com/problems/reverse-nodes-in-k-group/

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list. 
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
You may not alter the values in the nodes, only nodes itself may be changed.
Only constant memory is allowed.
For example,
 Given this linked list: 1->2->3->4->5 
For k = 2, you should return: 2->1->4->3->5 
For k = 3, you should return: 3->2->1->4->5 
**/

//@time complexity: O(n)
//@space compleixty: O(1)
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }
        
        ListNode * cur = head;
        ListNode * nextStart, * last;
        ListNode * prev = NULL;
        while (cur) {
            last = cur;
            if (!getNextStart(cur, k, nextStart)) {
                break;
            }
            cur = reverse(cur, k);
            if (prev == NULL) {
                head = cur;
            } else {
                prev->next = cur;
            }
            cur = nextStart;
            prev = last;
        }
        if (prev) {
            prev->next = cur;
        }
        
        return head;
    }
    
    ListNode * reverse(ListNode * head, int k) {
        if (k == 1) {
            return head;
        }
        
        ListNode * last = head->next;
        ListNode * ret = reverse(head->next, k - 1);
        last->next = head;
        return ret;
    }
    
    bool getNextStart(ListNode * head, int k, ListNode * & nextStartPos) {
        ListNode * cur = head;
        int count = 1;
        while (cur && count <= k) {
            cur = cur->next;
            count++;
        }
        
        nextStartPos = cur;
        if (count > k) {
            return true;
        } else {
            return false;
        }
    }
};