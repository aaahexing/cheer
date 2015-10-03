/*******************************
Decode Ways: https://leetcode.com/problems/decode-ways/

A message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.
For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
The number of ways decoding "12" is 2.
**/

//@time complexity: O(n)
//@space complexity: O(n)
//@2A
class Solution {
public:
    int numDecodings(string s) {
        int len = s.size();
        vector<int> iVec(len, 0);
        if (len == 0) {
            return 0;
        }
        
        iVec[len - 1] += checkAvail(s.substr(len - 1)) ? 1 : 0;
        if (len == 1) {
            return iVec[0];
        }
        
        iVec[len - 2] += checkAvail(s.substr(len - 2)) ? 1 : 0;
        iVec[len - 2] += checkAvail(s.substr(len - 2, 1)) ? iVec[len - 1] : 0;
        
        for (int i = len - 3; i >= 0; i--) {
            iVec[i] += checkAvail(s.substr(i, 2)) ? iVec[i + 2] : 0;
            iVec[i] += checkAvail(s.substr(i, 1)) ? iVec[i + 1] : 0;
        }
        
        return iVec[0];
    }
    
    bool checkAvail(string s) {
        stringstream ss;
        int val;
        ss << s;
        ss >> val;
        if ((s.size() == 1 && val >= 1 && val <= 9) || (s.size() == 2 && val >= 10 && val <= 26)) {
            return true; 
        } else {
            return false;
        }
    }
};
