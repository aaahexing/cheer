/**********************************
3Sum Closest : https://leetcode.com/problems/3sum-closest/

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
For example, given array S = {-1 2 1 -4}, and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
**/

//@time complexity: O(n^2)
//@space complexity: O(1)
//@2A, thinking out an O(n^3) time compleixity solution at first 
int threeSumClosest(vector<int>& nums, int target) {
	int ret = INT_MAX;
	sort(nums.begin(), nums.end());

	for (int i = 0; i + 3 <= nums.size(); i++) {
		int left = i + 1;
		int right = nums.size() - 1;
		while (left < right) {
			int tmp = nums[i] + nums[left] + nums[right];
			if (ret == INT_MAX) {
				ret = tmp;
			} else if (abs(target - tmp) < abs(target - ret)) {
				ret = tmp;
			}

			if (tmp < target) {
				left++;
			} else if (tmp > target) {
				right--;
			} else {
				return target;
			}
		}
	}

	return ret;
}