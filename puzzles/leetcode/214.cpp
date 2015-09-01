/******************************
Shortest Palindrome: https://leetcode.com/problems/shortest-palindrome/

Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation. 
For example: 
Given "aacecaaa", return "aaacecaaa".
Given "abcd", return "dcbabcd".
**/

//time complexity: O(n^2) in worst case
//space complexity: O(1) 
//time limit exceeded
string shortestPalindrome(string s) {
	string res;
	for(int len = s.size(); len >= 1; len--) {
		if (isPalindrome(s.substr(0, len))) {
			for(int i = len; i < s.size(); i++) {
				res = s[i] + res;
			}
			return res;
		}
	}

	return res;
}

bool isPalindrome(string s) {
	int start = 0;
	int end = s.size() -1;
	while (start <= end) {
		if (s[start] != s[end]) {
			return false;
		}
		start++;
		end--;
	}

	return true;
}