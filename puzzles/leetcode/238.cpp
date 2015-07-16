//Product of Array Except Self: https://leetcode.com/problems/product-of-array-except-self/
//Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
//Solve it without division and in O(n).
//For example, given [1,2,3,4], return [24,12,8,6]. 
//Follow up:
// Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)

//time complexity: O(n)
//space complexity: O(n)
vector<int> productExceptSelf(vector<int>& nums) {
	vector<int> before(nums.size());
	vector<int> after(nums.size());
	vector<int> res(nums.size());

	before[0] = after[nums.size() - 1] = 1;

	for(int i = 1; i < nums.size(); i++)
		before[i] = before[i-1] * nums[i-1];

	for(int i = nums.size() -2; i >= 0; i--)
		after[i] = after[i+1] * nums[i+1];

	for(int i = 0; i < nums.size(); i++)
		res[i] = before[i] * after[i];

	return res;
}

//time complexity: O(n)
//space complexity: O(1). Since the output array does not count as extra space for the purpose of space complexity analysis, the space complexity is O(1)
vector<int> productExceptSelf(vector<int>& nums) {
	int before = 1, after = 1;
	vector<int> res(nums.size(), 1);

	for(int i = 0; i < nums.size(); i++){
		res[i] *= before;
		before *= nums[i];
	}

	for(int i = nums.size() -1; i >= 0; i--){
		res[i] *= after;
		after *= nums[i];
	}

	return res;
}
