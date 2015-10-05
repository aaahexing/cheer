/*****************************
Combinations: https://leetcode.com/problems/combinations/

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
For example,
If n = 4 and k = 2, a solution is:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
**/

//@1A
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        if (k <= 0) {
            return ret;
        }
        vector<int> level;
        combine(1, n, k, ret, level);
        
        return ret;
    }
    
    void combine(int startNum, int endNum, int k, vector<vector<int>> & ret, vector<int> level) {
        if (endNum - startNum + 1 < k) {
            return;
        }
        if (k == 0) {
            ret.push_back(level);
            return;
        }
        
        for (int i = startNum; i <= endNum; i++) {
            level.push_back(i);
            combine(i + 1, endNum, k - 1, ret, level);
            level.pop_back();
        }
    }
};
