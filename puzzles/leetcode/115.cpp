/************************************
Distinct Subsequences : https://leetcode.com/problems/distinct-subsequences/

Given a string S and a string T, count the number of distinct subsequences of T in S. 
A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not). 
Here is an example:
S = "rabbbit", T = "rabbit" 
Return 3. 
**/

//@dynamic programming
//@time complexity: O(m*n)
//@space complexity: O(m*n)
//@2A
int numDistinct(string s, string t) {
	if (s.size() == t.size()) {
		return s == t ? 1 : 0;
	}
	if (s.size() < t.size()) {
		return 0;
	}

	vector<vector<int>> res(s.size(), vector<int>(t.size(), 0));
	for (int i = s.size() - 1; i >= 0; i--) {
		for (int j = t.size() - 1; j >= 0; j--) {
			if (j == t.size() - 1 && i == s.size() - 1) {
				res[i][j] = (s[i] == t[j] ? 1 : 0);
				continue;
			}

			if (s.size() - i < t.size() - j) {
				break;
			}
			res[i][j] = res[i + 1][j];
			if (s[i] == t[j]) {
				if (j != t.size() - 1) {
					res[i][j] += res[i + 1][j + 1];
				} else {
					res[i][j] += 1;
				}
			}
		}
	}

	return res[0][0];
}