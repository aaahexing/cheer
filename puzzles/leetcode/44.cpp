/********************************************
 Wildcard Matching : https://leetcode.com/problems/wildcard-matching/

 Implement wildcard pattern matching with support for '?' and '*'.
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
The function prototype should be:
bool isMatch(const char *s, const char *p)
Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "*") ¡ú true
isMatch("aa", "a*") ¡ú true
isMatch("ab", "?*") ¡ú true
isMatch("aab", "c*a*b") ¡ú false
**/

//-----------------------------------------solution 1-----------------------------
//@backtracking
//@TLE
class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.size() == 0 && p.size() == 0) {
            return true;
        }
        if (s.size() == 0) {
            if (p[0] == '*') {
                return isMatch(s, p.substr(1));
            } else {
                return false;
            }
        }
        if (p.size() == 0) {
            if (s[0] == '*') {
                return isMatch(s.substr(1), p);
            } else {
                return false;
            }
        }

        if (s[0] == '*') {
            bool ret = false;
            for (int i = 0; i <= p.size(); i++) {
                ret = ret || isMatch(s.substr(1), p.substr(i));
                if (ret) {
                    return true;
                }
            }
            return false;
        }
        if (p[0] == '*') {
            bool ret = false;
            for (int i = 0; i <= s.size(); i++) {
                ret = ret || isMatch(s.substr(i), p.substr(1));
                if (ret) {
                    return true;
                }
            }
            return false;
        }
        if (s[0] == '?' || p[0] == '?') {
            return isMatch(s.substr(1), p.substr(1));
        }
        return s[0] == p[0] ? isMatch(s.substr(1), p.substr(1)) : false;
    }
};

//--------------------------------------solution 2--------------------------------------
//@dynamic programming
//TLE
class Solution {
public:
    bool isMatch(string s, string p) {
        int len1 = s.size() + 1;
        int len2 = p.size() + 1;
        vector<vector<bool>> match(len1, vector<bool>(len2, false));
        match[0][0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= p.size(); j++) {
                if (s[i] == '*') {
                    for (int k = 1; k <= j; k++) {
                        if (match[i-1][k]) {
                            match[i][j] = true;
                            break;
                        }
                    }
                } else if (p[j] == '*') {
                    for (int k = 1; k <= i; k++) {
                        if (match[k][j-1]) {
                            match[i][j] = true;
                            break;
                        }
                    }
                } else if (s[i] == '?' || s[j] == '?') {
                    match[i][j] = match[i-1][j-1];
                } else {
                    match[i][j] = s[i] == p[j] ? match[i - 1][j - 1] : false;
                }
            }
        }
        
        return match[s.size()][p.size()];
    }
};