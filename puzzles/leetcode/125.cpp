/********************************
Valid Palindrome : https://leetcode.com/problems/valid-palindrome/

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases. 
For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome. 
Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.
For the purpose of this problem, we define empty string as valid palindrome. 
**/

//@time complexity: O(n)
//@space complexity: O(n)
//@2A
bool isPalindrome(string s) {
	string tmp;
	for (int i = 0; i < s.size(); i++) {
		if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
			tmp += s[i];
		}
	}

	int start = 0;
	int end = tmp.size() -1;
	while (start <= end) {
		char c1 = tmp[start], c2 = tmp[end];
		if (c1 >= 'A' && c1 <= 'Z') {
			c1 = 'a' + (c1 - 'A');
		}
		if (c2 >= 'A' && c2 <= 'Z') {
			c2 = 'a' + (c2 - 'A');
		}

		if (c1 != c2) {
			return false;
		}

		start++;
		end--;
	}

	return true;
}