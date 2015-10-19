/*********************************
Search Insert Position : https://leetcode.com/problems/search-insert-position/

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.
Here are few examples.
[1,3,5,6], 5 ¡ú 2
[1,3,5,6], 2 ¡ú 1
[1,3,5,6], 7 ¡ú 4
[1,3,5,6], 0 ¡ú 0 
**/

//@time complexity: O(logn)
//@space complexity: O(1)
//@1A
int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return 0;
        }
        int start = 0, end = nums.size() - 1;
        while (start < end) {
            int mid = start + (end - start) / 2;
            if (target == nums[mid]) {
                return mid;
            } else if (target < nums[mid]) {
                end = mid -1;
            } else {
                start = mid + 1;
            }
        }
        
        if (target > nums[start]) {
            return start + 1;
        } else {
            return start;
        }
    }