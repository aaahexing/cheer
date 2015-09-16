/*********************************
Find Minimum in Rotated Sorted Array : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.
You may assume no duplicate exists in the array.
**/

//@desc: 1. if (nums[start] < nums[end]), this is the sorted array;
//@desc: 2. others, this is a rotated sorted array, the rotated pos has the minimum number, try to find it
//@time complexity: O(logn)
//@space complexity: O(1)
int findMin(vector<int>& nums) {
	if (nums.size() == 1) {
		return nums[0];
	}

	int start = 0, end = nums.size() -1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (nums[start] < nums[end]) {
			return nums[start];
		}

		if (nums[mid] < nums[mid - 1]) {
			return nums[mid];
		} else if (nums[mid] > nums[end]) {
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}
}