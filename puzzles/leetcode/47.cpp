/************************************************
Permutations II : https://leetcode.com/problems/permutations-ii/

Given a collection of numbers that might contain duplicates, return all possible unique permutations. 
For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1]. 
**/

//@time complexity: O(n!)
//@space complexity: O(n^2)
//@1A
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.size() <= 0) {
            return ret;
        }
        
        if (nums.size() == 1) {
            ret.push_back(vector<int>(1, nums[0]));
            return ret;
        }
        
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) {
                continue;
            } else {
                s.insert(nums[i]);
            }
            swap(nums[0], nums[i]);
            vector<int> subNums(nums.begin() + 1, nums.end());
            vector<vector<int>> subRet = permuteUnique(subNums);
            for (int j = 0; j < subRet.size(); j++) {
                subRet[j].insert(subRet[j].begin(), nums[0]);
                ret.push_back(subRet[j]);
            }
            swap(nums[0], nums[i]);
        }
        
        return ret;
    }
};