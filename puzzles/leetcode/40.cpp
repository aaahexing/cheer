/*********************************
Combination Sum II : https://leetcode.com/problems/combination-sum-ii/

Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T. 
Each number in C may only be used once in the combination. 
Note:
•All numbers (including target) will be positive integers.
•Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
•The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
 A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
**/

//@space complexity: O(n)
//@2A
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ret;
        vector<int> cur;
        combinationSum2(ret, candidates, cur, 0, candidates.size() - 1, target);
        return ret;
    }
    
    void combinationSum2(vector<vector<int> > & ret, vector<int>& candidates, vector<int>& cur, int start, int end, int target) {
        if (target == 0) {
            ret.push_back(cur);
            return;
        } else if (start > end) {
            return;
        }
        
        for (int i = start; i <= end; i++) {
            if (target - candidates[i] >= 0) {
				if (i > start && candidates[i] == candidates[i - 1]) {
					continue;
				}
                cur.push_back(candidates[i]);
                combinationSum2(ret, candidates, cur, i+1, end, target-candidates[i]);
                cur.pop_back();
            } else {
                break;
            }
        }
    }
};