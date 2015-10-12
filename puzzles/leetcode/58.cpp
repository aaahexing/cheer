/********************************
Length of Last Word : https://leetcode.com/problems/length-of-last-word/

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
If the last word does not exist, return 0.
Note: A word is defined as a character sequence consists of non-space characters only.
For example, 
Given s = "Hello World",
return 5. 
**/

//@time complexity: O(n)
//@space complexity: O(1)
//@1A
int lengthOfLastWord(string s) {
	int wordLen = 0;
	int curLen = 0;
	if (s.size() <= 0) {
		return 0;
	}

	int pos = 0;
	while (pos < s.size()) {
		if (s[pos] == ' ') {
			if (curLen != 0) {
				wordLen = curLen;
			}
			curLen = 0;
		} else {
			curLen++;
		}
		pos++;
	}

	if (curLen != 0) {
		wordLen = curLen;
	}

	return wordLen;
}