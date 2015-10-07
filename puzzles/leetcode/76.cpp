/***************************************************
Minimum Window Substring: https://leetcode.com/problems/minimum-window-substring/

Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".
Note:
If there is no such window in S that covers all characters in T, return the empty string "".
If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
**/

//-------------------------------------------solution 1---------------------------------------
//@TLE
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tMap;
        unordered_map<char, int> subSMap;
        
        for (int i = 0; i < t.size(); i++) {
            tMap[t[i]]++;
        }
        
        int startIdx = 0, endIdx;
        string substr = "";
        while (startIdx < s.size()) {
            if (substr == "") {
                if (tMap.find(s[startIdx]) != tMap.end()) {
                    endIdx = startIdx;
                    subSMap[s[startIdx]]++;
                    while (endIdx < s.size()) {
                        if (!checkAvail(subSMap, tMap)) {
                            endIdx++;
                            if (endIdx < s.size() && tMap.find(s[endIdx]) != tMap.end()) {
                                subSMap[s[endIdx]]++;
                            }
                        } else {
                            substr = s.substr(startIdx, endIdx - startIdx + 1);
                            subSMap[s[startIdx]]--;
                            startIdx++;
                            break;
                        }
                    }
                    
                    if (substr == "") {
                        return substr;
                    }
                } else {
                    startIdx++;
                }
            } else {
                if (tMap.find(s[startIdx]) != tMap.end()) {
                    if (startIdx > endIdx) {
                        subSMap[s[startIdx]]++;
                        endIdx = startIdx;
                    }
                    while (endIdx < s.size()) {
                        if (!checkAvail(subSMap, tMap)) {
                            endIdx++;
                            if (endIdx < s.size() && tMap.find(s[endIdx]) != tMap.end()) {
                                subSMap[s[endIdx]]++;
                            }
                        } else {
                            string tmpStr = s.substr(startIdx, endIdx - startIdx + 1);
                            if (tmpStr.size() < substr.size()) {
                                substr = tmpStr;
                            }
                            break;
                        }
                    }
                    subSMap[s[startIdx]]--;
					startIdx++;
                } else {
                    startIdx++;
                }
            }
        }
        
        return substr;
    }
    
    bool checkAvail(unordered_map<char, int> & subSMap, unordered_map<char, int> & tMap) {
        for (unordered_map<char, int>::iterator itr = tMap.begin(); itr != tMap.end(); itr++) {
            if (subSMap.find(itr->first) == subSMap.end() || itr->second > subSMap[itr->first]) {
                return false;
            }
        }
        return true;
    }
};