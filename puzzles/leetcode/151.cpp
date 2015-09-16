/*********************************
Reverse Words in a String  : https://leetcode.com/problems/reverse-words-in-a-string/

Given an input string, reverse the string word by word. 
For example,
Given s = "the sky is blue",
return "blue is sky the". 
Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space. 
click to show clarification.
Clarification: 
•What constitutes a word?
A sequence of non-space characters constitutes a word.
•Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
•How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
**/

//@time complexity: O(n)
void reverseWords(string &s) {
	if (s.size() <= 0) {
		return ;
	}

	while(s[0] == ' ') {
		s.erase(0, 1);
		if (s.size() == 0) {
			return;
		}
	}
	while(s[s.size() - 1] == ' ') {
		s.erase(s.size() - 1, 1);
		if (s.size() == 0) {
			return;
		}
	}

	reverse(s.begin(), s.end());
	string rev, word;
	int firstChar = -1, firstSpace = -1, i = 0;
	for (i = 0; i < s.size(); i++) {
		if (s[i] != ' ') {
			if (firstChar == -1) {
				firstChar = i;
				firstSpace = -1;
			}
		} else {
			if (firstSpace == -1) {
				firstSpace = i;
				word = s.substr(firstChar, firstSpace - firstChar);
				reverse(word.begin(), word.end());
				rev += word + ' ';
				firstChar = -1;
			}
		}
	}

	if (firstSpace == -1) {
		word = s.substr(firstChar, s.size() - firstChar);
		reverse(word.begin(), word.end());
		rev += word;
	}

	s = rev;
}
