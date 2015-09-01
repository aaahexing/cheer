/***********************
Majority Element: https://leetcode.com/problems/majority-element/

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.
**/

//time compleixty: O(n)
//space complexity: O(1)
//2A：this can be solved by find middle, but time limit exceeding would occur......
int majorityElement(vector<int>& nums) {
    pair<int, int> majority;
    majority.first = nums[0];
    majority.second = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (majority.second == 0) {
            majority.first = nums[i];
            majority.second++;
            continue;
        }
            
        if (nums[i] == majority.first) {
            majority.second++;
        } else {
            majority.second--;
        }
    }
        
    return majority.first;
}

