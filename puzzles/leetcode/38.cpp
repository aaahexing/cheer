/**********************************************
Count and Say : https://leetcode.com/problems/count-and-say/

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ... 
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence. 
Note: The sequence of integers will be represented as a string. 
**/

//@time complexity: O(n)
//@space complexity: O(1)
//@1A
class Solution {
public:
    string countAndSay(int n) {
        string cur = "1";
        if (n == 1) {
            return cur;
        }
        
        for (int i = 2; i <= n; i++) {     //O(n)
            cur = nextSay(cur);
        }
        return cur;
    }
    
    string nextSay(string s) {            //O(m)
        vector<pair<char, int>> count;
        int curPos = 1, prevPos = 0;
        int num;
        while(curPos < s.size()) {
            if (s[curPos] != s[prevPos]) {
                pair<char, int> p = make_pair(s[prevPos], curPos - prevPos);
                count.push_back(p);
                prevPos = curPos;
            }
            curPos++;
        }
        
        pair<char, int> p = make_pair(s[prevPos], curPos - prevPos);
        count.push_back(p);
        
        string ret;
        for (int i = 0; i < count.size(); i++) {
            ret = ret + char(count[i].second + '0');
            ret = ret + count[i].first;
        }
        
        return ret;
    }
};