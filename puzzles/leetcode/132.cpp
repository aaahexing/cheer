/**************************************
Palindrome Partitioning II : https://leetcode.com/problems/palindrome-partitioning-ii/

Given a string s, partition s such that every substring of the partition is a palindrome. 
Return the minimum cuts needed for a palindrome partitioning of s.
For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut. 
**/

//@time complexity: O(n^2)
//@space complexity: O(n)
//time limit exceeded
int minCut(string s) {
	if (s.size() == 0) {
		return 0;
	}

	vector<int> min(s.size(), INT_MAX);
	for (int i = s.size() - 1; i >= 0; i--) {
		string sub = s.substr(i);
		if (isPalindrome(sub)) {
			min[i] = 0;
			continue;
		}

		for (int j = i + 1; j < s.size(); j++) {
			string sub = s.substr(i, j - i);
			if (isPalindrome(sub)) {
				if (min[j] + 1 < min[i]) {
					min[i] = min[j] + 1;
				}
			}
		}
	}

	return min[0];
}

bool isPalindrome(string s) {
	int start = 0, end = s.size() - 1;
	while (start <= end) {
		if (s[start] != s[end]) {
			return false;
		}
		start++;
		end--;
	}

	return true;
}