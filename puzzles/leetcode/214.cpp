/******************************
Shortest Palindrome: https://leetcode.com/problems/shortest-palindrome/

Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation. 
For example: 
Given "aacecaaa", return "aaacecaaa".
Given "abcd", return "dcbabcd".
**/
//---------------------------------------solution 1-----------------------------------------------
//time complexity: O(n^2) in worst case
//space complexity: O(1) 
//time limit exceeded
string shortestPalindrome(string s) {
	string res;
	for(int len = s.size(); len >= 1; len--) {
		if (isPalindrome(s.substr(0, len))) {
			for(int i = len; i < s.size(); i++) {
				res = s[i] + res;
			}
			return res;
		}
	}

	return res;
}

bool isPalindrome(string s) {
	int start = 0;
	int end = s.size() -1;
	while (start <= end) {
		if (s[start] != s[end]) {
			return false;
		}
		start++;
		end--;
	}

	return true;
}

//--------------------------------------solution 2----------------------------------------
//TLE 
class trieNode {
public:
    char val;
    trieNode * child;
    trieNode() {
        child = NULL;
    }
};

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        buildTree(s);
        reverse(rev.begin(), rev.end());
        int start;
        for (start = 0; start < rev.size(); start++) {
            if (foundInTree(s, start)) {
                break;
            }
        }
        string addStr = rev.substr(0, start + 1);
        s = addStr + s;
        return s;
    }
    
    //@time complexity: O(n)
    //@space complexity: O(1)
    void buildTree(string s) {
        if (s.size() <= 0) {
            return;
        }
        root = new trieNode();
        root->val = s[0];
        trieNode * cur = root;
        for (int i = 1; i < s.size(); i++) {
            cur->child = new trieNode();
            cur->child->val = s[i];
            cur = cur->child;
        }
    }
    
    bool foundInTree(string s, int start) {
        trieNode * cur = root;
        for (; start < s.size(); start++) {
            if(cur->val != s[start]) {
                return false;
            }
        }
        return true;
    }
   
    Solution() {
        root = NULL;
    }
private:
    trieNode * root;
};
