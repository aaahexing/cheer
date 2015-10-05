/*****************************
Sort Colors: https://leetcode.com/problems/sort-colors/

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
**/

//@time complexity: O(n)
//@space complexity: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int redPos = 0;
        int blackPos = nums.size() - 1;
        int pos = 0;
        while (pos < nums.size()) {
            if (nums[pos] == 0 && pos > redPos) {
                swap(nums[pos], nums[redPos]);
                redPos++;
            } else if (nums[pos] == 2 && pos < blackPos) {
                swap(nums[pos], nums[blackPos]);
                blackPos--;
            } else {
                pos++;
            }
        }
    }
    
    void swap(int & a, int & b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
};
