//Palindrome Linked List: https://leetcode.com/problems/palindrome-linked-list/
/******************************************************************************
Given a singly linked list, determine if it is a palindrome.
******************************************************************************/

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


//time complexity: O(n)
//space complexity: O(n)
bool isPalindrome(ListNode* head) {
	vector<int> tmp;
	bool res = true;
	while(head){
		tmp.push_back(head->val);
		head = head->next;
	}
	for(int i=0, j= tmp.size()-1; i<=j; i++, j--){
		if(tmp[i] != tmp[j]){
			res = false;
			break;
		}
	}
	return res;
}

//time complexity: O(n)
//space complexity: O(1)
bool isPalindrome(ListNode* head) {
	if(head == NULL)
		return true;

	bool res = true;
	int num = 0;
	ListNode * tmp = head;
	while(tmp){
		num++;
		tmp = tmp->next;
	}

	tmp = reverse(head, num/2);
	while(head && tmp){
		if(head->val != tmp->val){
			res = false;
			break;
		}
		head = head->next;
		tmp = tmp->next;
	}
	return res;
}

//reverse the list from index num
ListNode * reverse(ListNode * head, int num){
	int cnt = 0;
	while(cnt != num){
		cnt++;
		head = head->next;
	}

	ListNode * pre = head;
	ListNode * cur = head->next;
	pre->next = NULL;
	while(cur){
		ListNode * tmp = cur->next;
		cur->next = pre;
		pre = cur;
		cur = tmp;
	}

	return pre;
}