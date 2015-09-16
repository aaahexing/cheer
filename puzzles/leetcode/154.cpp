/*************************************
Find Minimum in Rotated Sorted Array II : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/


Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.
The array may contain duplicates.
**/

//@desc: line 22-27 are basic conditions, especially notify the last else condition
//@time complexity: O(logn) on average and O(n) in the worst case
//@space complexity: O(1)
int findMin(vector<int>& nums) {
	if (nums.size() == 1) {
		return nums[0];
	}

	int start = 0, end = nums.size() -1;
	while (start <= end) {
		if (start == end) {
			return nums[start];
		}

		int mid = start + (end - start) / 2;
		if (nums[mid] < nums[end]) {
			end = mid;
		} else if (nums[mid] > nums[end]) {
			start = mid + 1;
		} else {
			end--;
		}
	}
}