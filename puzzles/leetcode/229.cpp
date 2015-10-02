/***********************************
Majority Element II: https://leetcode.com/problems/majority-element-ii/

Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
**/

//@time complexity: O(n)
//@space complexity: O(1)
vector<int> majorityElement(vector<int>& nums) {
    vector<int> res;
    pair<int, int> first;
    pair<int, int> second;
    first.second = second.second = 0;
        
    for (int i = 0; i < nums.size(); i++) {
        if (first.second == 0) {
            if (second.second != 0 && second.first == nums[i]) {
                second.second++;
            } else {
                first.first = nums[i];
                first.second++;
            }
        } else if (second.second == 0) {
            if (first.second != 0 && first.first == nums[i]) {
                first.second++;
            } else {
                second.first = nums[i];
                second.second++;
            }
        } else {
            if (nums[i] == first.first) {
                first.second++;
            } else if (nums[i] == second.first) {
                second.second++;
            } else {
                first.second--;
                second.second--;
            }
        }
    }
        
    int count[2] = {0, 0};
    for (int i = 0; i < nums.size(); i++) {
        if (first.second > 0 && nums[i] == first.first) {
            count[0]++;
        } else if (second.second > 0 && nums[i] == second.first) {
            count[1]++;
        }
    }
        
    if (count[0] > nums.size()/3) {
        res.push_back(first.first);
    } 
        
    if (count[1] > nums.size()/3) {
        res.push_back(second.first);
    }
        
    return res;
}
