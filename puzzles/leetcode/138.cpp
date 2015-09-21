/**********************************
Copy List with Random Pointer:https://leetcode.com/problems/copy-list-with-random-pointer/

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null. 
Return a deep copy of the list. 
**/

// Definition for singly-linked list with a random pointer.
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

//@time complexity: O(n);
//@space complexity: O(n)
//1A 
RandomListNode *copyRandomList(RandomListNode *head) {
	if (head == NULL) {
		return NULL;
	}

	unordered_map<RandomListNode *, RandomListNode *> m;
	RandomListNode * ret;
	RandomListNode * cur = head;
	while (cur) {
		ret = new RandomListNode(cur->label);
		m[cur] = ret;
		ret = ret->next;
		cur = cur->next;
	}

	cur = head;
	while (cur) {
		m[cur]->next = m[cur->next];
		m[cur]->random = m[cur->random];
		cur = cur->next;
	}

	return m[head];
}