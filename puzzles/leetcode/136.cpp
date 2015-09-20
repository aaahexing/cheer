/*******************************
Single Number : https://leetcode.com/problems/single-number/

Given an array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
**/

//@time complexity: O(n)
//@space complexity: O(1)
//1A
int singleNumber(vector<int>& nums) {
	int ret = 0;
	for (int i = 0; i < nums.size(); i++) {
		ret ^= nums[i];
	}
	return ret;
}