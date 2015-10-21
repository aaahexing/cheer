/********************************
Substring with Concatenation of All Words : https://leetcode.com/problems/substring-with-concatenation-of-all-words/

You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters. 
For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"] 
You should return the indices: [0,9].
 (order does not matter). 
**/

//------------------------solution 1-------------------------
//@TLE
//@time complexity: O(m*n)
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        if (words.size() <= 0 || s.size() <= 0) {
            return ret;
        }
        unordered_map<string, int> dict;
        int totalLen = words.size() * words[0].size();
        for (int startIdx = 0; startIdx + totalLen <= s.size(); startIdx++) {        //O(n)
            createDict(words, dict);                                                 //O(m)
            for (int curIdx = startIdx; curIdx < startIdx + totalLen; curIdx += words[0].size()) {
                string curWord = s.substr(curIdx, words[0].size());
                if (dict.find(curWord) != dict.end()) {
                    dict[curWord]--;
                    if (dict[curWord] == 0) {
                        dict.erase(curWord);
                    }
                    if (dict.empty()) {
                        ret.push_back(startIdx);
                    }
                } else {
                    break;
                }
            }
        }
        
        return ret;
    }
    
    void createDict(vector<string>& words, unordered_map<string, int>& dict) {
        dict.clear();
        for (int i = 0; i < words.size(); i++) {
            if (dict.find(words[i]) != dict.end()) {
                dict[words[i]]++;
            } else {
                dict[words[i]] = 1;
            }
        }
    }
};

//-----------------------------------------solution 2------------------------------------
//@time complexity: O(m*n) in worst case
//@space complexity: O(m)
//@AC
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        if (words.size() <= 0 || s.size() <= 0) {
            return ret;
        }
        unordered_map<string, int> dict;
		unordered_map<string, int> dictUsed;
        int totalLen = words.size() * words[0].size();
        createDict(words, dict);                                             //O(m)
		for (int startIdx = 0; startIdx + totalLen <= s.size(); startIdx++) {    //O(n)
            recorveryDict(dict, dictUsed);
            for (int curIdx = startIdx; curIdx < startIdx + totalLen; curIdx += words[0].size()) {   //O(m)
                string curWord = s.substr(curIdx, words[0].size());
                if (dict.find(curWord) != dict.end()) {
                    dict[curWord]--;
					if (dictUsed.find(curWord) != dictUsed.end()) {
						dictUsed[curWord]++;
					} else {
						dictUsed[curWord] = 1;
					}
                    if (dict[curWord] == 0) {
                        dict.erase(curWord);
                    }
                    if (dict.empty()) {
                        ret.push_back(startIdx);
                    }
                } else {
                    break;
                }
            }
        }
        
        return ret;
    }
    
    void createDict(vector<string>& words, unordered_map<string, int>& dict) {
        dict.clear();
        for (int i = 0; i < words.size(); i++) {
            if (dict.find(words[i]) != dict.end()) {
                dict[words[i]]++;
            } else {
                dict[words[i]] = 1;
            }
        }
    }

	void recorveryDict(unordered_map<string, int>& dict, unordered_map<string, int>& dictUsed) {
		for (unordered_map<string, int>::iterator itr = dictUsed.begin(); itr != dictUsed.end(); itr++) {
			if (dict.find(itr->first) != dict.end()) {
				dict[itr->first] += itr->second;
			} else {
				dict[itr->first] = itr->second;
			}
		}
		dictUsed.clear();
	}
};