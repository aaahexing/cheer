/******************************************
Longest Valid Parentheses : https://leetcode.com/problems/longest-valid-parentheses/

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring. 
For "(()", the longest valid parentheses substring is "()", which has length = 2. 
Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4. 
**/

//--------------------------------------solution 1-----------------------------------------------
//@time complexity: O(n)
//@space complexity: O(n)
//@DP
int longestValidParentheses(string s) {
	int len = s.size();
	vector<int> vecLen(s.size(), 0);  //record the longest valid substring started from i
	for (int i = len - 1; i >= 0; i--) {
		if (i == len - 1 || s[i] == ')') {   
			vecLen[i] = 0;
		} else {
			vecLen[i] = (s[i + vecLen[i+1] + 1] == ')' ? 2 + vecLen[i+1] : 0);
			if (i + vecLen[i+1] + 1 < len - 1 && s[i + vecLen[i+1] + 1] == ')') {
				vecLen[i] += vecLen[i+vecLen[i+1]+2];
			} 
		}
	}

	int max = 0;
	for (int i = 0; i < len; i++) {
		if (vecLen[i] > max) {
			max = vecLen[i];
		}
	}

	return max;
}

//------------------------------------------solution 2-----------------------------------------------
//@time complexity: O(n)
//@space complexity: O(n)
//@stack
int longestValidParentheses(string s) {
	stack<int> st;
	int maxLen = 0;
	int lastPos = -1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			st.push(i);
		} else {
			if (st.empty()) {
				lastPos = i;
			} else {
				st.pop();
				if (st.empty()) {
					maxLen = max(maxLen, i - lastPos);
				} else {
					maxLen = max(maxLen, i - st.top());
				}
			}
		}
	}

	return maxLen;
}