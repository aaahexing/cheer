/***************************************
Word Break : https://leetcode.com/problems/word-break/

Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words. 
For example, given
s = "leetcode",
dict = ["leet", "code"]. 
Return true because "leetcode" can be segmented as "leet code". 
**/

//------------------------------------solution 1---------------------------
//@desc: backtracking....
//@time limit exceeded for some special case
bool wordBreak(string s, unordered_set<string>& wordDict) {
	if (s.size() <= 0) {
		return false;
	}

	if (wordDict.find(s) != wordDict.end()) {
		return true;
	}

	bool ret = false;
	for (int i = 0; i < s.size() - 1; i++) {
		string sub = s.substr(0, i + 1);
		if (wordDict.find(sub) != wordDict.end()) {
			ret = ret || wordBreak(s.substr(i + 1), wordDict);
			if (ret) {
				break;
			}
		}
	}

	return ret;
}

//------------------------------------solution 2-----------------------------
//@desc: dynamic programming
//@time complexity: O(n^2)
//@space complexity: O(n)
//2A
bool wordBreak(string s, unordered_set<string>& wordDict) {
	if (s.size() <= 0) {
		return false;
	}

	vector<bool> tmpRes(s.size(), false);
	for (int i = s.size() -1; i >= 0; i--) {
		string sub = s.substr(i);
		if (wordDict.find(sub) != wordDict.end()) {
			tmpRes[i] = true;
			continue;
		}
		for (int j = i + 1; j < s.size(); j++) {
			sub = s.substr(i, j - i);
			if (wordDict.find(sub) != wordDict.end() && tmpRes[j]) {
				tmpRes[i] = true;
				break;
			}
		}
	}

	return tmpRes[0];
}