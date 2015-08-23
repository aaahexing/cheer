/****************
Single Number III: https://leetcode.com/problems/single-number-iii/
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. 
For example: 
Given nums = [1, 2, 1, 3, 2, 5], return [3, 5]. 
**/

//time complexity: O(n)
//space complexity: O(1)
vector<int> singleNumber(vector<int>& nums) {
	vector<int> res;
	res.clear();

	if (nums.size() < 2) {
		return res;
	}

	int tmp = 0;
	for (int i = 0; i < nums.size(); i++) {
		tmp ^= nums[i];
	}

	tmp = getLowInt(tmp);
	int left = 0, right = nums.size() -1;
	while (left <= right) {
		while ((nums[left] & tmp) && (left < nums.size())) left++;
		while (!(nums[right] & tmp) && (right >= 0)) right--;
		if (left <= right) { 
			swap(nums[left], nums[right]);
		}
	}

	tmp = 0;
	for (int i = 0; i <= right; i++) {
		tmp ^= nums[i];
	}
	res.push_back(tmp);

	tmp = 0;
	for (int i = left; i < nums.size(); i++) {
		tmp ^= nums[i];
	}
	res.push_back(tmp);

	return res;
}

int getLowInt(int a) {
	int i = 1;
	while(a) {
		if (a & i) {
			return i;
		}
		i <<= 1;
	}
}

void swap(int & a, int & b) {
	int tmp = a;
	a = b;
	b = tmp;
}

