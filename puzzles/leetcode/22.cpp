/***************************************
Generate Parentheses : https://leetcode.com/problems/generate-parentheses/

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses. 
For example, given n = 3, a solution set is: 
"((()))", "(()())", "(())()", "()(())", "()()()" 
**/

//@time complexity: O(m) m is num of return string
//@space complexity: O(1)
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vStr;
        string tStr(2*n, ')');
        generateParenthesis(vStr, tStr, n, 0, n);
        return vStr;
    }
    
    void generateParenthesis(vector<string> & vStr, string tStr, int n, int index, int k) {
        if (k == 0) {
            vStr.push_back(tStr);
            return ;
        }
        if (index >= tStr.size()) {
            return;
        }
        
        for (int i = index; i < tStr.size() - 1; i++) {
            tStr[i] = '(';
            int leftNum = n - k + 1;
            int rightNum = (i + 1) - leftNum;
            if (leftNum <= rightNum) {
                break;
            }
            generateParenthesis(vStr, tStr, n, i + 1, k - 1);
            tStr[i] = ')';
        } 
    }
};