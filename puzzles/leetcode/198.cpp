/********************
house robber: https://leetcode.com/problems/house-robber/

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
**/

//dynamic programming
//time compleixty: O(n)
//space complexity: O(n)
//2A: recursive is used in the first time and cause the time limit exceeding
int rob(vector<int>& nums) {
	if (nums.size() <= 0) {
		return 0;
	}
	if (nums.size() == 1) {
		return nums[0];
	}

	int size = nums.size();
	vector<int> sum(size, 0);
	sum[size - 1] = nums[size - 1];
	sum[size - 2] = max(nums[size - 1], nums[size - 2]);
	for (int i = nums.size() -3; i >= 0; i--) {
		int first = nums[i] + sum[i+2];
		int second = sum[i+1];
		sum[i] = max(first, second);
	}

	return sum[0];
}

int max(int a, int b) {
	return a > b ? a : b;
}