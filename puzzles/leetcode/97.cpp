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

//--------------------------forth solution------------------------------
//@TLE
//@DP
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size() + 1;
        int len2 = s2.size() + 1;
        
        //dpMem[i+1][j+1] s1[0…i]^s2[0…j] ->vector<string> 
        vector<vector<vector<string>>> dpMem(len1, vector<vector<string>>(len2));
        
        dpMem[0][0].push_back("");
        for (int i = 0; i < s1.size(); i++) {
            dpMem[i+1][0].push_back(s1.substr(0, i+1));
        }
        for (int j = 0; j < s2.size(); j++) {
            dpMem[0][j+1].push_back(s2.substr(0, j+1));
        }
        
        for (int i = 0; i < s1.size(); i++) {
            for (int j = 0; j < s2.size(); j++) {
                for (int l1 = 0; l1 <= i + 1; l1++) {
                    for (int r1 = 0; r1 <= j + 1; r1++) {
                        int l2 = (i + 1) - l1;
                        int r2 = (j + 1) - r1;
                        if ((l1 == 0 && r1 == 0) || (l2 == 0 && r2 == 0)) {
                            continue;
                        }
                        for (int m = 0; m < dpMem[l1][r1].size(); m++) {
                            for (int n = 0; n < dpMem[l2][r2].size(); n++) {
                                dpMem[i+1][j+1].push_back(dpMem[l1][r1][m] + dpMem[l2][r2][n]);
                            }
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i < dpMem[s1.size()][s2.size()].size(); i++) {
            if (s3 == dpMem[s1.size()][s2.size()][i]) {
                return true;
            }
        }
        
        return false;
    }
};

//-------------------------------solution fifth-------------------------------------
//@time complexity: O(m*n)
//@space complexity: O(m*n)
//@DP
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size() + 1;
        int len2 = s2.size() + 1;
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }
        
        vector<vector<bool>> dpMem(len1, vector<bool>(len2, false));
        dpMem[0][0] = true;
        for (int i = 0; i < s1.size(); i++) {
            dpMem[i+1][0] = (s1.substr(0, i+1) == s3.substr(0, i+1) ? true : false);
        }
        for (int j = 0; j < s2.size(); j++) {
            dpMem[0][j+1] = (s2.substr(0, j+1) == s3.substr(0, j+1) ? true : false);
            cout<<s2.substr(0, j+1)<<endl;
        }

        for (int i = 0; i < s1.size(); i++) {
            for (int j = 0; j < s2.size(); j++) {
                dpMem[i+1][j+1] = (dpMem[i][j+1] && (s1[i] == s3[i+j+1])) || (dpMem[i+1][j] && (s2[j] == s3[i+j+1]));
            }
        }
        
        return dpMem[s1.size()][s2.size()];
    }
};
