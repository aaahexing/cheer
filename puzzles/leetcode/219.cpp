/***********************
Contains Duplicate II: https://leetcode.com/problems/contains-duplicate-ii/

Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
**/


//@time complexity: O(n); n equals to the length of the input array
//@space complexity: O(n)
//@2A : especially be careful of the usage of the unordered_multimap
bool containsNearbyDuplicate(vector<int>& nums, int k) {
	unordered_multimap<int, int> m;
	for (int i = 0; i < nums.size(); i++) {
		int key = nums[i];
		int value = i;
		pair<int, int> ele(key, value);
		m.insert(ele);
	}

	for (int i = 0; i < nums.size(); i++) {
		pair<unordered_multimap<int, int>::iterator, unordered_multimap<int, int>::iterator> range = m.equal_range(nums[i]);
		int min = nums.size() , max = -1;
		for (unordered_multimap<int, int>::iterator itr = range.first; itr != range.second; itr++) {
			if (itr->second < min) {
				min = itr->second;
			}

			if (itr->second > max) {
				max = itr->second;
			}

			if (max - min <= k && max != min) {
				return true;
			}
		}

		m.erase(nums[i]);
	}

	return false;
}