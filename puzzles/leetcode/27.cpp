/************************************
Remove Element : https://leetcode.com/problems/remove-element/

Given an array and a value, remove all instances of that value in place and return the new length. 
The order of elements can be changed. It doesn't matter what you leave beyond the new length. 
**/

//@time complexity: O(n)
//@space complexity: O(1)
//@2A
int removeElement(vector<int>& nums, int val) {
	int putPos = 0, elePos = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[elePos] == val) {
			elePos++;
		} else {
			nums[putPos] = nums[elePos];
			putPos++;
			elePos++;
		}
	}

	return putPos;
}