/**************************
Search in Rotated Sorted Array: https://leetcode.com/problems/search-in-rotated-sorted-array/

Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
**/

//@time complexity: O(logn)
//@space complexity: O(1)
//@2A, error for missing the judge condition in line 24-31
int search(vector<int>& nums, int target) {
    if (nums.size() <= 0) {
        return -1;
    }
        
    int start = 0, end = nums.size() - 1;
    while (start <= end) {
        int mid = start + (end - start)/2;
        if (target == nums[mid]) {
            return mid;
        } else {
            if (mid == start) {
                start = start + 1;
                continue;
            } 
            if (mid == end) {
                end = end - 1;
                continue;
            }
            if (nums[start] < nums[mid]) {
                if (target >= nums[start] && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
    }
        
    return -1;
}
