/**********************************************
Valid Parentheses: https://leetcode.com/problems/valid-parentheses/

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
**/

//@time complexity: O(n)
//@space compleixity: O(n)
//@2A, condition in line 19 was not considered caused the first failure..
class Solution {
public:
    bool isValid(string s) {
        stack<char> sChar;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                sChar.push(s[i]);
            } else {
                if (sChar.empty()) {
                    return false;
                }
                if (s[i] == ')') {
                    if (sChar.top() != '(') {
                        return false;
                    } else {
                        sChar.pop();
                    }
                } else if (s[i] == ']') {
                    if (sChar.top() != '[') {
                        return false;
                    } else {
                        sChar.pop();
                    }
                } else {
                    if (sChar.top() != '{') {
                        return false;
                    } else {
                        sChar.pop();
                    }
                }
            }
        }
        
        if (sChar.empty()) {
            return true;
        } else {
            return false;
        }
    }
};