/*******************************************
Valid Number : https://leetcode.com/problems/valid-number/

Validate if a given string is numeric.
Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. 
**/

//@time complexity: O(n)
//@space complexity: O(n)
//@NA,,,,,so so so many to be considered....
class Solution {
public:
    bool isNumber(string s) {
        s = removeFrontSpace(s);
        s = removeBackSpace(s);
        if (s.size() <= 0) {
            return false;
        }
        int ret;
        if (s[0] == '+' || s[0] == '-') {
            ret = isNumberRe(s.substr(1));
        } else {
            ret = isNumberRe(s);
        }
        if (ret == 1 || ret == 2 || ret == 3) {
            return true;
        } else {
            return false;
        }
    }
    
    //return: 0-> s is empty; 1->s is an interger; 2->s is a float; 3->s is e format; 4->s is not a number
    int isNumberRe(string s) {
        if (s.size() <= 0) {
            return 0;
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (isChar(s[i])) {
                if (s[i] != 'e' && s[i] != 'E') {
                    return 4;
                }
                
                int leftRet = isNumberRe(s.substr(0, i));
                string rightStr = s.substr(i+1);
                int rightRet;
                if (rightStr[0] == '+' || rightStr[0] == '-') {
                    rightRet = isNumberRe(rightStr.substr(1));
                } else {
                    rightRet = isNumberRe(rightStr);
                }
                if ((leftRet == 1 || leftRet == 2) && rightRet == 1) {
                    return 3;
                } else {
                    return 4;
                }
            }
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (!isDigit(s[i])) {
                if (s[i] != '.') {
                    return 4;
                }
                int leftRet = isNumberRe(s.substr(0, i));
                int rightRet = isNumberRe(s.substr(i+1));
                if ((leftRet == 0 || leftRet == 1) &&(rightRet == 0 || rightRet == 1) && !(leftRet == 0 && rightRet == 0)) {
                    return 2;
                } else {
                    return 4;
                }
            }
        }
        
        return 1;
    }
    
    bool isChar(char c) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            return true;
        } else {
            return false;
        }
    }
    
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }
    
    string removeFrontSpace(string s) {
        int pos = 0;
        while (pos < s.size()) {
            if (s[pos] != ' ') {
                break;
            }
            pos++;
        }
        return s.substr(pos);
    }
    
    string removeBackSpace(string s) {
        int pos = s.size() - 1;
        while (pos >= 0) {
            if (s[pos] != ' ') {
                break;
            }
            pos--;
        }
        return s.substr(0, pos + 1);
    }
};