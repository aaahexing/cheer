/*******************************************
Subsets II: https://leetcode.com/problems/subsets-ii/

Given a collection of integers that might contain duplicates, nums, return all possible subsets.
Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
**/

//@1A .....crying.....
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<int, int> m;
        vector<vector<int>> ret;
        vector<int> curVec;
        ret.push_back(curVec);
        getMap(nums, m);
        for (int i = 1; i <= nums.size(); i++) {
            getCurLevelVec(ret, m, curVec, i);
        }
        
        return ret;
    }
    
    void getMap(vector<int>& nums, map<int, int> & m) {
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) == m.end()) {
                m[nums[i]] = 1;
            } else {
                m[nums[i]]++;
            }
        }
    }
    
    void getCurLevelVec(vector<vector<int>> & retVec, map<int, int> & m, vector<int> curVec, int level) {
        if (level == 0) {
            retVec.push_back(curVec);
            return;
        }
        
        int max = curVec.size() == 0 ? INT_MIN : curVec[curVec.size() - 1];
        for (map<int, int>::iterator itr = m.begin(); itr != m.end(); itr++) {
            if (itr->first >= max && itr->second >= 1) {
                curVec.push_back(itr->first);
                itr->second--;
                getCurLevelVec(retVec, m, curVec, level - 1);
                curVec.pop_back();
                itr->second++;
            }
        }
    }
};
