/******
Valid Anagram: https://leetcode.com/problems/valid-anagram/
Given two strings s and t, write a function to determine if t is an anagram of s.
For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false. 
**/

//time complexity: O(s.size() + t.size())
//space complexity: O(1);
bool isAnagram(string s, string t) {
	int charNum[26];
	memset(charNum, 0, sizeof(int) * 26);

	for (int i = 0; i < s.size(); i++) {
		charNum[s[i] - 'a']++;
	}

	for (int i = 0; i < t.size(); i++) {
		charNum[t[i] - 'a']--;
	}

	for (int i = 0; i < 26; i++) {
		if (charNum[i] != 0) {
			return false;
		}
	}

	return true;
}
