/************************************
3Sum: https://leetcode.com/problems/3sum/

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note:
•Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
•The solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4},
A solution set is:
(-1, 0, 1)
(-1, -1, 2)
**/

//@time complexity: O(n^2)
//@space complexity: O(1)
//@2A, duplicate triplets caused the first failure...Notice the judgement method...
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> ret;
	sort(nums.begin(), nums.end());

	for (int i = 0; i + 3 <= nums.size(); i++) {
		if (i > 0 && nums[i] == nums[i - 1]) {
			continue;
		}
		int left = i +  1;
		int right = nums.size() - 1;
		while (left < right) {
			int tmp = nums[i] + nums[left] + nums[right];
			if (tmp == 0) {
				vector<int> tmp;
				tmp.push_back(nums[i]);
				tmp.push_back(nums[left]);
				tmp.push_back(nums[right]);
				ret.push_back(tmp);
				while(left + 1 < nums.size() && nums[left+1] == nums[left]) left++;
				while (right - 1 >= 0 && nums[right-1] == nums[right]) right--;
				left++; right--; 
			} else if (tmp < 0) {
				left++;
			} else {
				right--;
			}
		}
	}

	return ret;
}