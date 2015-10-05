/*********************************
Subsets: https://leetcode.com/problems/subsets/

Given a set of distinct integers, nums, return all possible subsets.
Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
**/

//@1A
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        vector<int> level;
        ret.push_back(level);
        
        for (int len = 1; len <= nums.size(); len++) {
            subsets(nums, ret, level, len, 0);
        }
        
        return ret;
    }
    
    void subsets(vector<int>& nums, vector<vector<int>> & ret, vector<int> level, int len, int startIdx) {
        if (len == 0) {
            ret.push_back(level);
            return;
        }
        
        for (; startIdx + len <= nums.size(); startIdx++) {
            level.push_back(nums[startIdx]);
            subsets(nums, ret, level, len - 1, startIdx + 1);
            level.pop_back();
        }
    }
};
