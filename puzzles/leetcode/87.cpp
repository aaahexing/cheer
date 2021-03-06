/*****************************
Scramble String: https://leetcode.com/problems/scramble-string/

Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
**/

//--------------------------solution 1----------------------------
//@violant solution
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        
        if (s1.size() != s2.size()) {
            return false;
        }
        
        if (!hasSameChar(s1, s2)) {
            return false;
        }
        
        for (int len = 1; len < s1.size(); len++) {
            string subS11 = s1.substr(0, len);
            string subS12 = s1.substr(len);
            string subS21a = s2.substr(0, len);
            string subS22a = s2.substr(len);
            string subS21b = s2.substr(0, s1.size() - len);
            string subS22b = s2.substr(s1.size() - len);
            
            if (isScramble(subS11, subS21a) && isScramble(subS12, subS22a)) {
                return true;
            }
            if (isScramble(subS11, subS22b) && isScramble(subS12, subS21b)) {
                return true;
            }
        }
        
        return false;
    }
    
    bool hasSameChar(string s1, string s2) {
        int c1[52] = {0};
        int c2[52] = {0};
        
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] >= 'a' && s1[i] <= 'z') {
                c1[s1[i] - 'a']++;
            } else {
                c1[26 + s1[i] - 'A']++;
            }
            
            if (s2[i] >= 'a' && s2[i] <= 'z') {
                c2[s2[i] - 'a']++;
            } else {
                c2[26 + s2[i] - 'A']++;
            }
        }
        
        for (int i = 0; i < 52; i++) {
            if (c1[i] != c2[i]) {
                return false;
            }
        }
        
        return true;
    }
};

//------------------------solution 2-------------------------
//@dynamic programming
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        
        if (s1.size() != s2.size()) {
            return false;
        }
        
        vector<vector<vector<bool>>> res(s1.size() + 1, vector<vector<bool>>(s1.size(), vector<bool>(s1.size(), false))); //res[len][i][j] i represents the start pos of s1 and j represents the start pos of s2
        
        for (int len = 1; len <= s1.size(); len++) {
            for (int i = 0; i + len <= s1.size(); i++) {
                for (int j = 0; j + len <= s2.size(); j++) {
                    string subS1 = s1.substr(i, len);
                    string subS2 = s2.substr(j, len);
                    if (subS1 == subS2) {
                        res[len][i][j] = true;
                    } else {
                        for (int sublen = 1; sublen < len; sublen++) {
                            res[len][i][j] = res[len][i][j] || (res[sublen][i][j] && res[len - sublen][i + sublen][j + sublen]);
                            res[len][i][j] = res[len][i][j] || (res[sublen][i][j + (len - sublen)] && res[len - sublen][i + sublen][j]);
                            if (res[len][i][j]) {
                                break;
                            }
                        }
                    }
                }
            }
        }
        
        return res[s1.size()][0][0];
    }
};
