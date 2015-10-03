/*******************************************
Restore IP Addresses: https://leetcode.com/problems/restore-ip-addresses/

Given a string containing only digits, restore it by returning all possible valid IP address combinations.
For example:
Given "25525511135",
return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
**/

//@space complexity: O(1)
//@time complexity: O(3^4)
//@2A: be special careful of the checkIP function and line37
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> vecStr;
        string IP;
        restoreIpAddresses(s, IP, vecStr, 4);
        return vecStr;
    }
    
    void restoreIpAddresses(string s, string IP, vector<string> & vecStr, int num) {
        if (num == 0 && s.size() == 0) {
            vecStr.push_back(IP);
            return;
        } else if (num == 0 || s.size() == 0) {
            return;
        }
        
        for (int len = 1; len <= s.size() && len <= 3; len++) {
            string tmpIP = s.substr(0, len);
            if (checkIP(tmpIP)) {
                tmpIP = IP + tmpIP;
                if (num != 1) {
                    tmpIP = tmpIP + '.';
                }
                restoreIpAddresses(s.substr(len), tmpIP, vecStr, num-1);
            }
        }
    }
    
    bool checkIP(string tmpIP) {
        int size = tmpIP.size();
        stringstream ss;
        int ipVal;
        ss << tmpIP;
        ss >> ipVal;
        
        if (size == 1) {
            return true;
        } else if (size > 1) {
            if (tmpIP[0] == '0' || (size == 3 && ipVal > 255)) {
                return false; 
            } else {
                return true;
            }
        }
    }
};
