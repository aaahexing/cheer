/**********************
Isomorphic Strings : https://leetcode.com/problems/isomorphic-strings/

Given two strings s and t, determine if they are isomorphic.
Two strings are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
For example,
Given "egg", "add", return true.
Given "foo", "bar", return false.
Given "paper", "title", return true
Note:
You may assume both s and t have the same length.
**/

//time complexity: O(n)
//space complexity: O(n)
//1A
bool isIsomorphic(string s, string t) {
	unordered_map<char, char> m;
	for (int i = 0; i < s.size(); i++) {
		if (m.find(s[i]) == m.end()) {
			m[s[i]] = t[i];
		} else {
			if (m.at(s[i]) != t[i]) {
				return false;
			}
		}
	} 

	m.clear();

	for (int i = 0; i < t.size(); i++) {
		if (m.find(t[i]) == m.end()) {
			m[t[i]] = s[i];
		} else {
			if (m.at(t[i]) != s[i]) {
				return false;
			}
		}
	} 

	return true;
}