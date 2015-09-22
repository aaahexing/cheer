/*************************************
Palindrome Partitioning : https://leetcode.com/problems/palindrome-partitioning/

Given a string s, partition s such that every substring of the partition is a palindrome. 
Return all possible palindrome partitioning of s. 
For example, given s = "aab",
Return 
[
["aa","b"],
["a","a","b"]
]
**/

//@violent
//@1A....
vector<vector<string>> partition(string s) {
	vector<vector<string>> ret;
	if (s.size() <= 0) {
		return ret;
	}

	vector<string> tmpVec;
	partition(s, ret, tmpVec);
	return ret;
}

void partition(string s, vector<vector<string>> & ret, vector<string> & tmpVec) {
	if (s.size() == 0) {
		if (tmpVec.size() > 0) {
			ret.push_back(tmpVec);
		}
		return;
	}

	for (int i = 0; i < s.size(); i++) {
		string sub = s.substr(0, i + 1);
		if (isPalindrome(sub)) {
			tmpVec.push_back(sub);
			partition(s.substr(i + 1), ret, tmpVec);
			tmpVec.pop_back();
		}
	}
}

bool isPalindrome(string s) {
	int startIdx, endIdx;
	startIdx = 0;
	endIdx = s.size() - 1;
	while (startIdx <= endIdx) {
		if (s[startIdx] != s[endIdx]) {
			return false;
		}
		startIdx++;
		endIdx--;
	}

	return true;
}