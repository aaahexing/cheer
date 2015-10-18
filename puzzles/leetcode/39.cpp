/**************************************
Combination Sum : https://leetcode.com/problems/combination-sum/

Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T. 
The same repeated number may be chosen from C unlimited number of times. 
Note:
•All numbers (including target) will be positive integers.
•Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
•The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
 A solution set is: 
[7] 
[2, 2, 3] 
**/

//@backtracking
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ret;
        vector<int> cur;
        combinationSum(ret, candidates, cur, 0, candidates.size() - 1, target);
        return ret;
    }
    
    void combinationSum(vector<vector<int> > & ret, vector<int>& candidates, vector<int>& cur, int start, int end, int target) {
        if (target == 0) {
            ret.push_back(cur);
            return;
        } else if (start > end) {
            return;
        }
        
        for (int i = start; i <= end; i++) {
            for (int j = 1; j <= target / candidates[i]; j++) {
                if (target - j * candidates[i] >= 0) {
                    cur.push_back(candidates[i]);
                    combinationSum(ret, candidates, cur, i+1, end, target-candidates[i] * j);
                }
            }
            for (int j = 1; j <= target / candidates[i]; j++) {
                cur.pop_back();
            }
        }
    }
};