/***************************************
Interleaving String: https://leetcode.com/problems/interleaving-string/

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
For example,
Given:
s1 = "aabcc",
s2 = "dbbca",
When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
**/

//--------------------------------solution 1-----------------------------------
//@TLE 
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()) {
            return false;
        }
        
        if (s1.size() == 0) {
            return s2 == s3;
        } else if (s2.size() == 0) {
            return s1 == s3;
        }
        
        int preS1 = getMaxPrefix(s1, s3);
        int preS2 = getMaxPrefix(s2, s3);
        bool ret = false;
        
        for (int len = preS1; len >= 1; len--) {
            ret = ret || isInterleave(s1.substr(len), s2, s3.substr(len));
            if (ret) {
                return true;
            }
        }
        
        for (int len = preS2; len >= 1; len--) {
            ret = ret || isInterleave(s1, s2.substr(len), s3.substr(len));
            if (ret) {
                return true;
            }
        }
        
        return ret;
    }
    
    int getMaxPrefix(string s1, string s2) {
        int ret = 0;
        for (int i = 0; i < min(s1.size(), s2.size()); i++) {
            if (s1[i] == s2[i]) {
                ret++;
            } else {
                break;
            }
        }
        
        return ret;
    }
};

//---------------------------------------solution 2--------------------------------
//@error exists in line 68
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        unordered_map<pair<string, string>, bool> m;
        return isInterleave(s1, s2, s3, m);
    }
    
    bool isInterleave(string s1, string s2, string s3, unordered_map<pair<string, string>, bool> & m) {
        if (s3.size() != s1.size() + s2.size()) {
            return false;
        }
        
        if (s1.size() == 0) {
            return s2 == s3;
        } else if (s2.size() == 0) {
            return s1 == s3;
        }
        
        pair<string, string> p = make_pair(s1, s2);
        if (m.find(p) != m.end()) {
            return m[p];
        }
        
        int preS1 = getMaxPrefix(s1, s3);
        int preS2 = getMaxPrefix(s2, s3);
        bool ret = false;
        
        for (int len = preS1; len >= 1; len--) {
            ret = ret || isInterleave(s1.substr(len), s2, s3.substr(len));
            if (ret) {
                return true;
            }
        }
        
        for (int len = preS2; len >= 1; len--) {
            ret = ret || isInterleave(s1, s2.substr(len), s3.substr(len));
            if (ret) {
                return true;
            }
        }
        
        m[p] = ret;
        return ret;
    }
    
    int getMaxPrefix(string s1, string s2) {
        int ret = 0;
        for (int i = 0; i < min(s1.size(), s2.size()); i++) {
            if (s1[i] == s2[i]) {
                ret++;
            } else {
                break;
            }
        }
        
        return ret;
    }
};

//----------------------------------------solution 3------------------------------
//@TLE
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        unordered_map<string, bool> m;
        return isInterleave(s1, s2, s3, m);
    }
    
    bool isInterleave(string s1, string s2, string s3, unordered_map<string, bool> & m) {
        if (s3.size() != s1.size() + s2.size()) {
            return false;
        }
        
        if (s1.size() == 0) {
            return s2 == s3;
        } else if (s2.size() == 0) {
            return s1 == s3;
        }
        
        if (m.find(s3) != m.end() && m[s3] == true) {
            return true;
        }
        
        int preS1 = getMaxPrefix(s1, s3);
        int preS2 = getMaxPrefix(s2, s3);
        bool ret = false;
        
        for (int len = preS1; len >= 1; len--) {
            ret = ret || isInterleave(s1.substr(len), s2, s3.substr(len), m);
            if (ret) {
                m[s3] = true;
                return true;
            }
        }
        
        for (int len = preS2; len >= 1; len--) {
            ret = ret || isInterleave(s1, s2.substr(len), s3.substr(len), m);
            if (ret) {
                m[s3] = true;
                return true;
            }
        }
        
        m[s3] = ret;
        return ret;
    }
    
    int getMaxPrefix(string s1, string s2) {
        int ret = 0;
        for (int i = 0; i < min(s1.size(), s2.size()); i++) {
            if (s1[i] == s2[i]) {
                ret++;
            } else {
                break;
            }
        }
        
        return ret;
    }
};
