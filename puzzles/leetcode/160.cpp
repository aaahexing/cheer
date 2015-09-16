/***********************
Intersection of Two Linked Lists: https://leetcode.com/problems/intersection-of-two-linked-lists/

Write a program to find the node at which the intersection of two singly linked lists begins.
For example, the following two linked lists:
A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.

Notes:
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//@time complexity: O(n)
//@space complexity: O(1)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int len1 = 0;
    int len2 = 0;
    int lenDis;
    ListNode * curA = headA, * curB = headB;
    len1 = getLength(headA);
    len2 = getLength(headB);
    lenDis = abs(len1 - len2);
        
    if (len1 > len2) {
        while(lenDis > 0) {
            curA = curA->next;
            lenDis--;
        }
    }
        
    if (len2 > len1) {
        while(lenDis > 0) {
            curB = curB->next;
            lenDis--;
        }
    }
        
    while (curA != curB) {
        curA = curA->next;
        curB = curB->next;
    }
        
    return curA;
}
    
int getLength(ListNode * h) {
    ListNode * cur = h;
    int len = 0;
    while (cur) {
        len++;
        cur = cur->next;
    }
        
    return len;
}
