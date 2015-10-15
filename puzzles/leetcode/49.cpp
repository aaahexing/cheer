/**************************************
Group Anagrams : https://leetcode.com/problems/anagrams/

Given an array of strings, group anagrams together. 
For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
 Return: 
[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:
1.For the return value, each inner list's elements must follow the lexicographic order.
2.All inputs will be in lower-case.
**/

//@time complexity: O(n*mlogm), n is the number of string, and m is the maximum length of string
//@space complexity: O(n)
//@2A
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        vector<vector<string>> ret;
        for (int i = 0; i < strs.size(); i++) {   //O(n)
            string tmp = strs[i];               
            sort(tmp.begin(), tmp.end());         //O(mlogm)
            m[tmp].push_back(strs[i]);
        }
        
        for (map<string, vector<string>>::iterator itr = m.begin(); itr != m.end(); itr++) {
            sort((itr->second).begin(), (itr->second).end());
            ret.push_back(itr->second);
        }
        
        return ret;
    }
};