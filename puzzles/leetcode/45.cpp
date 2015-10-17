/*************************************
Jump Game II : https://leetcode.com/problems/jump-game-ii/

Given an array of non-negative integers, you are initially positioned at the first index of the array. 
Each element in the array represents your maximum jump length at that position. 
Your goal is to reach the last index in the minimum number of jumps. 
For example:
Given array A = [2,3,1,1,4] 
The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.) 
**/

//@Greedy algorithm
//@time complexity : O(n)
//@space complexity: O(1)
int jump(vector<int>& nums) {
	int step = 0;
	int maxReach = 0;
	int nextMaxReach = 0;
	for (int i = 0; i <= maxReach; i++) {
		if (maxReach >= nums.size() - 1) {
			break;
		}
		if (i + nums[i] > nextMaxReach) {
			nextMaxReach = i + nums[i];
		}
		if (i == maxReach && nextMaxReach > maxReach) {
			maxReach = nextMaxReach;
			step++;
		}
	}

	if (maxReach >= nums.size() - 1) {
		return step;
	} else {
		return -1;
	}
}