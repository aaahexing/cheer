/************************************
Merge k Sorted Lists : https://leetcode.com/problems/merge-k-sorted-lists/

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity. 
**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Comparison {
public:
    bool operator() (ListNode * list1, ListNode * list2) {
        if (list1->val > list2->val) {
            return true;
        } else {
            return false;
        }
    }
};

//@time complexity: O(m * n), the total number of elements
//@space compleixity: O(n), the number of the lists
//@2A, the compare is a little wield, I should confirm the usage of it..
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode * head = NULL;
        ListNode * cur = NULL;
        priority_queue<ListNode*, vector<ListNode*>, Comparison> pQueue;
        buildHeap(pQueue, lists);
        
        while(!pQueue.empty()) {
            if (cur == NULL) {
                head = cur = pQueue.top();
            } else {
                cur->next = pQueue.top();
                cur = cur->next;
            }
            ListNode * next = (pQueue.top())->next;
            pQueue.pop();
            if (next) {
                pQueue.push(next);
            }
        }
        if (cur) {
            cur->next = NULL;
        }
        return head;
    }
    
    void buildHeap(priority_queue<ListNode *, vector<ListNode *>, Comparison> & pQueue, vector<ListNode *> & lists) {
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                pQueue.push(lists[i]);
            }
        }
    }
};