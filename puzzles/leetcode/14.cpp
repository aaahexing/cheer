/********************************
Longest Common Prefix : https://leetcode.com/problems/longest-common-prefix/

Write a function to find the longest common prefix string amongst an array of strings. 
**/

//@time complexity: O(n*m) m is the length of the common prefix and n is the nums of string
//@space complexity: O(1)
//@1A
string longestCommonPrefix(vector<string>& strs) {
	string ret;
	if (strs.size() <= 0) {
		return ret;
	}
	for (int i = 0; i < strs[0].size(); i++) {
		char tmp = strs[0][i];
		int j = 1;
		for (; j < strs.size(); j++) {
			if (i >= strs[j].size() || strs[j][i] != tmp) {
				break;
			} 
		}
		if (j == strs.size()) {
			ret += tmp;
		} else {
			break;
		}
	}

	return ret;
}

