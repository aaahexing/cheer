/*********************
House Robber II: https://leetcode.com/problems/house-robber-ii/

Note: This is an extension of House Robber.
After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street. 
Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
**/

//dynamic programming
//time complexity: O(n)
//space complexity: O(n)
//1A: this can be converted as house robber
int rob(vector<int>& nums) {
	if (nums.size() <= 0) {
		return 0;
	}

	int first = 0, second = 0;
	vector<int>::iterator itrStart = nums.begin();
	vector<int>::iterator itrEnd = nums.end();

	itrStart++;
	if (itrStart <= itrEnd) {
		first = robNoCircle(vector<int>(itrStart, itrEnd));
	}

	itrStart++;
	itrEnd--;
	if (itrStart <= itrEnd) {
		second = robNoCircle(vector<int>(itrStart, itrEnd));
	}

	return max(first, second + nums[0]);
}

//time compleixty: O(n)
//space compleixty: O(n)
int robNoCircle(vector<int> nums) {
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