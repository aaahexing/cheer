/*************************
Contains Duplicate: https://leetcode.com/problems/contains-duplicate/

Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
**/

//@time complexity: O(n)
//@space complexity: O(n)
bool containsDuplicate(vector<int>& nums) {
	unordered_multimap<int, int> m;
	for (int i = 0; i < nums.size(); i++) {
		pair<int, int> ele(nums[i], i);
		m.insert(ele);
	}

	for (int i = 0; i < nums.size(); i++) {
		pair<unordered_map<int, int>::iterator, unordered_map<int, int>::iterator> range = m.equal_range(nums[i]);
		int count = 0;
		for (unordered_map<int, int>::iterator itr = range.first; itr != range.second; itr++) {
			count++;
		}
		m.erase(nums[i]);

		if (count >= 2) {
			return true;
		}
	}

	return false;
}