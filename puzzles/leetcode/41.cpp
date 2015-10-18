/********************************
First Missing Positive: https://leetcode.com/problems/first-missing-positive/

Given an unsorted integer array, find the first missing positive integer. 
For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2. 
Your algorithm should run in O(n) time and uses constant space. 
**/

//@time complexity: O(n)
//@space complexity: O(1)
int firstMissingPositive(vector<int>& nums) {
	int size = nums.size();
	if (size <= 0) {
		return 1;
	}

	for (int i = 0; i < size; ) {
		if (nums[i] > size || nums[i] <= 0 || nums[i] == nums[nums[i] - 1]) {
			i++;
			continue;
		}
		swap(nums[i], nums[nums[i] - 1]);
	}

	for (int i = 0; i < size; i++) {
		if (nums[i] != i + 1) {
			return i + 1;
		}
	}
	return size + 1;
}