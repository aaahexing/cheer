/******************* ************
Maximum Product Subarray: https://leetcode.com/problems/maximum-product-subarray/

Find the contiguous subarray within an array (containing at least one number) which has the largest product. 
For example, given the array [2,3,-2,4], the contiguous subarray [2,3] has the largest product = 6. 
**/

//@desc: find the relationship between local max and global max;
//@desc: local max means the max value including the current element, global max means the max value in global
//@desc: since a negative integer multipled by a negative integer leads to a positive integer, 
//@desc: so, not only the local max but also the local min should be reserved 
//@desc: localMin = min(lastLocalMin * curValue, lastLocalMax * curValue, curValue)
//@desc: localMax = max(lastLocalMin * curValue, lastLocalMax * curValue, curValue)
//@desc: since the subarray contains at least one number, the global value must be one of the localMax, 
//@desc: so, update the global max after each local max is calculated.
//@time complexity: O(n)
//@space complexity: O(1)
int maxProduct(vector<int>& nums) {
	if (nums.size() == 1) {
		return nums[0];
	}

	int maxProduct = nums[0];
	int curMax = nums[0];
	int curMin = nums[0];

	for (int i = 1; i < nums.size(); i++) {
		int tmp = nums[i] * curMax;
		curMax = max(nums[i], max(tmp, nums[i] * curMin));
		curMin = min(nums[i], min(tmp, nums[i] * curMin));
		if (curMax > maxProduct) {
			maxProduct = curMax;
		}
	}

	return maxProduct;
}