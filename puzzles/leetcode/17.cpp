/*******************************************
Letter Combinations of a Phone Number : https://leetcode.com/problems/letter-combinations-of-a-phone-number/

Given a digit string, return all possible letter combinations that the number could represent. 
A mapping of digit to letters (just like on the telephone buttons) is given below.
**/

//backtracking....
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> m(10);
        initialize(m);
        
        vector<string> ret;
        ret = letterCombinations(m, digits, 0);

		return ret;
    }
    
    void initialize(vector<vector<char>> & m) {
        m[2].push_back('a'); m[2].push_back('b'); m[2].push_back('c');
        m[3].push_back('d'); m[3].push_back('e'); m[3].push_back('f');
        m[4].push_back('g'); m[4].push_back('h'); m[4].push_back('i');
        m[5].push_back('j'); m[5].push_back('k'); m[5].push_back('l');
        m[6].push_back('m'); m[6].push_back('n'); m[6].push_back('o');
        m[7].push_back('p'); m[7].push_back('q'); m[7].push_back('r'); m[7].push_back('s');
        m[8].push_back('t'); m[8].push_back('u'); m[8].push_back('v');
        m[9].push_back('w'); m[9].push_back('x'); m[9].push_back('y'); m[9].push_back('z');
    }
    
    vector<string> letterCombinations(vector<vector<char>> & m, string digits, int index) {
        vector<string> ret;
        if (index == digits.size()) {
            return ret;
        }

        vector<string> recur = letterCombinations(m, digits, index + 1);
		if (m[digits[index] - '0'].size() <= 0) {
			return recur;
		}
		for (int i = 0; i < m[digits[index] - '0'].size(); i++) {
			if (recur.size() > 0) {
				for (int j = 0; j < recur.size(); j++) {
		            string tmp = m[digits[index] - '0'][i] + recur[j];
			        ret.push_back(tmp);
				}
			} else {
				string tmp(1, m[digits[index] - '0'][i]);
				ret.push_back(tmp);
			}
        }
        
        return ret;
    }
};