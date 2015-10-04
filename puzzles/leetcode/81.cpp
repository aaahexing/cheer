/*****************************
Search in Rotated Sorted Array II: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Write a function to determine if a given target is in the array.
**/

//@time complexity: O(logn) on average and O(n) on worst case
//@space complexity: O(1)
//@1A
bool search(vector<int>& nums, int target) {
    if (nums.size() <= 0) {
        return false;
    }
        
    int start = 0, end = nums.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            return true;
        }
            
        if (nums[start] < nums[mid]) {
            if (target >= nums[start] && target < nums[mid]) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else if (nums[start] == nums[mid]) {
            start = start + 1;
        } else {
            if (target > nums[mid] && target <= nums[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
        
    return false;
}
