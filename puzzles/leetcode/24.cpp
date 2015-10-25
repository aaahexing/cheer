/*************************************
Swap Nodes in Pairs : https://leetcode.com/problems/swap-nodes-in-pairs/

Given a linked list, swap every two adjacent nodes and return its head. 
For example,
 Given 1->2->3->4, you should return the list as 2->1->4->3. 
Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed. 
**/

//@time complexity: O(n)
//@space complexity: O(1)
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode * cur = head;
        ListNode * nextStart, * last;
        ListNode * prev = NULL;
        while (cur) {
            last = cur;
            if (!getNextStart(cur, 2, nextStart)) {
                break;
            }
            cur = reverse(cur, 2);
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