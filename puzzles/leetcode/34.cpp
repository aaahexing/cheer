/*****************************
Search for a Range : https://leetcode.com/problems/search-for-a-range/

Given a sorted array of integers, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].
For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4]. 
**/

//@time complexity: O(logn) in average time and O(n) in worst case
//@space complexity: O(1)
//@1A
vector<int> searchRange(vector<int>& nums, int target) {
	vector<int> ret(2, -1);
	if (nums.size() == 0) {
		return ret;
	}
	int start = 0, end = nums.size() - 1;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (target == nums[mid]) {
			int leftPos = mid;
			while (leftPos >= 0 && nums[leftPos] == target) {
				leftPos--;
			}
			ret[0] = leftPos + 1;
			int rightPos = mid;
			while (rightPos < nums.size() && nums[rightPos] == target) {
				rightPos++;
			}
			ret[1] = rightPos - 1;
			return ret;
		} else if (target < nums[mid]) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}

	return ret;
}