/***********************
Minimum Size Subarray Sum : https://leetcode.com/problems/minimum-size-subarray-sum/

Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ¡Ý s. If there isn't one, return 0 instead. 
For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint. 
**/

//time complexity: O(n)
//space complexity: O(n)
//3A: misunderstanding the puzzle caused the first failure
int minSubArrayLen(int s, vector<int>& nums) {
	if (nums.size() <= 0) {
		return 0;
	}

	vector<int> sum(nums.size(), 0);
	int len = 1;
	int idxFirst = 0;
	int idxSecond = idxFirst + len - 1;
	int exceedNum = 0;

	while (len <= nums.size()) {
		if (idxSecond >= nums.size()) {
			len++;
			idxFirst = 0;
			idxSecond = idxFirst + len - 1;
			if (exceedNum >= nums.size()) {
				break;
			}
			if (len > nums.size()) {
				break;
			}
			exceedNum = 0;
		}

		sum[idxFirst] += nums[idxSecond];
		if (sum[idxFirst] >= s) {
			return len;
		}
		if (sum[idxFirst] > s) {
			exceedNum++;
		}
		idxFirst++;
		idxSecond++;
	} 

	return 0;
}