/************************************
Multiply Strings : https://leetcode.com/problems/multiply-strings/

Given two numbers represented as strings, return multiplication of the numbers as a string.
Note: The numbers can be arbitrarily large and are non-negative.
**/

//@time complexity: O(m * n)
//@space complexity: O(max(m, n))
//@1A
class Solution {
public:
    string multiply(string num1, string num2) {
        string before = "", cur;
        for (int i = num2.size() - 1; i >= 0; i--) {
            cur = mul(num1, num2[i]);
            if (i < num2.size() - 1) {
                cur = cur + string(num2.size() - 1 - i, '0');
            }
            cur = add(cur, before);
            before = cur;
        }
        before = trip(before);
        if (before.size() == 0) {
            before = "0";
        }
        return before;
    }
    
private:
    string mul(string num1, char num2) {
        string ret;
        char jinwei = '0';
        for (int i = num1.size() - 1; i >= 0; i--) {           //must be started from the least significant bit
            int tmp = (num1[i] - '0') * (num2 - '0') + (jinwei - '0');
            jinwei = (tmp / 10) + '0';
            char cur = (tmp % 10) + '0';
            ret = ret + cur;
        }
        
        if (jinwei != '0') {
            ret = ret + jinwei;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    
    string add(string num1, string num2) {
        if (num1.size() == 0 && num2.size() == 0) {
            return "0";
        } else if (num1.size() == 0) {
            return num2;
        } else if (num2.size() == 0) {
            return num1;
        }
        
        string ret;
        char jinwei = '0';
        int pos1 = num1.size() - 1;
        int pos2 = num2.size() - 1;
        for (; pos1 >= 0 && pos2 >= 0; pos1--, pos2--) {
            int tmp = (num1[pos1] - '0') + (num2[pos2] - '0') + (jinwei - '0');
            jinwei = (tmp / 10) + '0';
            char cur = (tmp % 10) + '0';
            ret = ret + cur;
        }
        
        if (pos1 < 0) {
            while (pos2 >= 0) {
                int tmp = (num2[pos2] - '0') + (jinwei - '0');
                jinwei = (tmp / 10) + '0';
                char cur = (tmp % 10) + '0';
                ret = ret + cur;
                pos2--;
            }
        }
        
        if (pos2 < 0) {
            while (pos1 >= 0) {
                int tmp = (num1[pos1] - '0') + (jinwei - '0');
                jinwei = (tmp / 10) + '0';
                char cur = (tmp % 10) + '0';
                ret = ret + cur;
                pos1--;
            }
        }
        
        if (jinwei != '0') {
            ret = ret + jinwei;
        }
        
        reverse(ret.begin(), ret.end());
        return ret;
    }
    
    string trip(string num) {
        string ret;
        int pos = 0;
        while (pos < num.size() && num[pos] == '0') {  //position test must be done firstly, then, its value
            pos++;
        }
        ret = num.substr(pos);
		return ret;
    }
};