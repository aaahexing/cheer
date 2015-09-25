/*****************************************
Word Ladder : https://leetcode.com/problems/word-ladder/

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that: 
1.Only one letter can be changed at a time
2.Each intermediate word must exist in the word list
For example, 
Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 return its length 5. 
Note:
•Return 0 if there is no such transformation sequence.
•All words have the same length.
•All words contain only lowercase alphabetic characters.
**/

//------------------------------------------------first solution----------------------------------
//@DFS
//@TLE
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        int dis = 0;
        wordList.erase(beginWord);
        wordList.erase(endWord);
        return ladderLength(beginWord, endWord, wordList, dis);
    }
    
    int ladderLength(string beginWord, string endWord, unordered_set<string> wordList, int dis) {
        if (wordList.empty()) {
            return 0;
        }
        if (getDis(beginWord, endWord) == 1) {
            return dis + 1;
        }
        
        vector<string> disOneWord = findAllDisOne(beginWord, wordList);
        if (disOneWord.size() <= 0) {
            return 0;
        }
        
        int minDis = INT_MAX;
        for (int i = 0; i < disOneWord.size(); i++) {
            int tmp = ladderLength(disOneWord[i], endWord, wordList, dis + 1);
            if (tmp < minDis && tmp != 0) {
                minDis = tmp;
            }
        }
        
        if (minDis == INT_MAX) {
            return 0;
        } else {
            return minDis;
        }
    }
    
    int getDis(string s1, string s2) {
        int count = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                count++;
            }
        }
        
        return count;
    }
    
    vector<string> findAllDisOne(string beginWord, unordered_set<string> & wordList) {
        vector<string> ret;
		char dic[26];
		for (int i = 0; i < 26; i++) {
			dic[i] = 'a' + i;
		}

        for (int i = 0; i < beginWord.size(); i++) {
			string tmpWord = beginWord;
			for (int j = 0; j < 26; j++) {
				if (dic[j] != beginWord[i]) {
					tmpWord[i] = dic[j];
					if (wordList.find(tmpWord) != wordList.end()) {
						ret.push_back(tmpWord);
						wordList.erase(tmpWord);
					}
				}
			}
		}
        
        return ret;
    }
};


//------------------------------------------------second solution---------------------------------
//@BFS
//@AC
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        int dis = 1;
        int count = 1;
        queue<string> q;
        char dic[26];
        for (int i = 0; i < 26; i++) {
            dic[i] = 'a' + i;
        }
        
        wordList.erase(beginWord);
        q.push(beginWord);
        while(!q.empty()) {
            string word = q.front();
            q.pop();
            count--;
            for (int i = 0; i < word.size(); i++) {
                string tmp = word;
                for (int j = 0; j < 26; j++) {
                    if (tmp[i] != dic[j]) {
                        tmp[i] = dic[j];
                        if (tmp == endWord) {
                            return dis + 1;
                        }
                        if (wordList.find(tmp) != wordList.end()) {
                            q.push(tmp);
                            wordList.erase(tmp);
                        }
                    }
                }
            }
            
            if (count == 0) {
                dis++;
                count = q.size();
            }
        }
        
        return 0;
    }
};