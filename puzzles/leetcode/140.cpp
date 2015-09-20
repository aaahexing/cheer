/****************************************
Word Break II: https://leetcode.com/problems/word-break-ii/

Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
Return all such possible sentences
For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].
A solution is ["cats and dog", "cat sand dog"].
**/

//-------------------------------------solution 1------------------------------------
//TLE
//@backtracking
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> ret;
        wordBreak(s, wordDict, ret, "");
        return ret;
    }
    
    void wordBreak(string s, unordered_set<string> & wordDict, vector<string> & ret, string str) {
        if (s.size() <= 0) {
            if (str.size() > 0) {
                ret.push_back(str);
            }
            return;
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (wordDict.find(s.substr(0, i + 1)) != wordDict.end()) {
                string tmp;
                if (str.size() == 0) {
                    tmp = str + s.substr(0, i + 1);
                } else {
                    tmp = str + " " + s.substr(0, i + 1);
                }
                wordBreak(s.substr(i + 1), wordDict, ret, tmp);
            }
        }
    }
};

//-----------------------------------------------------solution 2-------------------------------------------------
//TLE
//@@backtracking
class TrieNode {
public:
    TrieNode * child[26];
    bool isFullWord;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
            isFullWord = false;
        }
    }
};

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        createDicTree(wordDict);
        vector<string> ret;
        wordBreak(s, ret, "");
        return ret;
    }
    
    Solution() {
        root = new TrieNode();
    }
private:
    TrieNode * root;
    void createDicTree(unordered_set<string>& wordDict) {
        for (unordered_set<string>::iterator itr = wordDict.begin(); itr != wordDict.end(); itr++) {
            insertWord(*itr);
        }
    }
    
    void insertWord(const string s) {
        TrieNode * cur = root;
        for (int i = 0; i < s.size(); i++) {
            if (cur->child[s[i] - 'a'] == NULL) {
                cur->child[s[i] - 'a'] = new TrieNode();
            }
            cur = cur->child[s[i] - 'a'];
        }
        cur->isFullWord = true;
    }
    
    void wordBreak(string s, vector<string> & ret, string str) {
        if (s.size() <= 0) {
            if (str.size() > 0) {
                ret.push_back(str);
            }
            return;
        }
        
        TrieNode * cur = root;
        for (int i = 0; i < s.size(); i++) {
            if (cur->child[s[i] - 'a']) {
                if (cur->child[s[i] - 'a']->isFullWord) {
                    if (str.size() == 0) {
                        str = str + s.substr(0, i + 1);
                    } else {
                        str = str + " " + s.substr(0, i + 1);
                    }
                    wordBreak(s.substr(i + 1), ret, str);
                }
                cur = cur->child[s[i] - 'a'];
            } else {
                break;
            }
        }
    }
};

//---------------------------------------------------------solution 3-----------------------------------------------
//@dynamic programming
//TLE....
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<vector<string> > tmpRes(s.size());
        
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < s.size(); j++) {
                string sub = s.substr(i, j - i);
                if (wordDict.find(sub) != wordDict.end()) {
                    for (int m = 0; m < tmpRes[j].size(); m++) {
                        tmpRes[i].push_back(sub + " " + tmpRes[j][m]);
                    }
                }
            }
            
            string sub = s.substr(i);
            if (wordDict.find(sub) != wordDict.end()) {
                tmpRes[i].push_back(sub);
            }
        }
        
        return tmpRes[0];
    }
};

//--------------------------------------------------------------solution 4-------------------------------------------------
//@desc: dynamic programming + backtracking.....solution 1 + 139.cpp.....I am going to be crying....
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> tmpRes(s.size(), false);
    	vector<string> strRes;
    	if (s.size() <= 0) {
		    return strRes;
	    }
    	for (int i = s.size() -1; i >= 0; i--) {
    		string sub = s.substr(i);
    		if (wordDict.find(sub) != wordDict.end()) {
    			tmpRes[i] = true;
    			continue;
    		}
    		for (int j = i + 1; j < s.size(); j++) {
    			sub = s.substr(i, j - i);
    			if (wordDict.find(sub) != wordDict.end() && tmpRes[j]) {
    				tmpRes[i] = true;
    				break;
    			}
    		}
    	}

    	if (tmpRes[0] == false) {
    	    return strRes;
    	}
    	
        wordBreak(s, wordDict, strRes, "");
        return strRes;
    }
    
    void wordBreak(string s, unordered_set<string> & wordDict, vector<string> & ret, string str) {
        if (s.size() <= 0) {
            if (str.size() > 0) {
                ret.push_back(str);
            }
            return;
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (wordDict.find(s.substr(0, i + 1)) != wordDict.end()) {
                string tmp;
                if (str.size() == 0) {
                    tmp = str + s.substr(0, i + 1);
                } else {
                    tmp = str + " " + s.substr(0, i + 1);
                }
                wordBreak(s.substr(i + 1), wordDict, ret, tmp);
            }
        }
    }
};

//-----------------------------------------solution 5------------------------------------------------------
//@desc: dynamic programming.....solution 3 + 139.cpp....................still crying............
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> tmpRes(s.size(), false);
    	vector<vector<string> > strRes(s.size());
    	if (s.size() <= 0) {
		    return strRes[0];
	    }
    	for (int i = s.size() -1; i >= 0; i--) {
    		string sub = s.substr(i);
    		if (wordDict.find(sub) != wordDict.end()) {
    			tmpRes[i] = true;
    			continue;
    		}
    		for (int j = i + 1; j < s.size(); j++) {
    			sub = s.substr(i, j - i);
    			if (wordDict.find(sub) != wordDict.end() && tmpRes[j]) {
    				tmpRes[i] = true;
    				break;
    			}
    		}
    	}

    	if (tmpRes[0] == false) {
    	    return strRes[0];
    	}
    	
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < s.size(); j++) {
                string sub = s.substr(i, j - i);
                if (wordDict.find(sub) != wordDict.end()) {
                    for (int m = 0; m < strRes[j].size(); m++) {
                        strRes[i].push_back(sub + " " + strRes[j][m]);
                    }
                }
            }
            
            string sub = s.substr(i);
            if (wordDict.find(sub) != wordDict.end()) {
                strRes[i].push_back(sub);
            }
        }
        
        return strRes[0];
    }
};