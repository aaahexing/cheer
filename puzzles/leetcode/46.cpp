/*********************************
Permutations : https://leetcode.com/problems/permutations/

Given a collection of numbers, return all possible permutations. 
For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1]. 
**/

//@time complexity: O(n!)
//@space complexity: O(n^2)
//@1A
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.size() <= 0) {
            return ret;
        }
        
        if (nums.size() == 1) {
            vector<int> curVec(1, nums[0]);
            ret.push_back(curVec);
            return ret;
        }
        
        for (vector<int>::iterator itr = nums.begin(); itr != nums.end(); itr++) {
            int tmp = *itr;
            itr = nums.erase(itr);
            vector<vector<int>> subRet = permute(nums);
            for (int j = 0; j < subRet.size(); j++) {
                subRet[j].insert(subRet[j].begin(), tmp);
				ret.push_back(subRet[j]);
            }
            itr = nums.insert(itr, tmp);
        }
        return ret;
    }
};