/***************************
Longest Consecutive Sequence : https://leetcode.com/problems/longest-consecutive-sequence/

Given an unsorted array of integers, find the length of the longest consecutive elements sequence. 
For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4. 
Your algorithm should run in O(n) complexity. 
**/

//@time complexity; O(n)
//@space complexity: O(n)
//@1A
int longestConsecutive(vector<int>& nums) {
	unordered_set<int> s;
	for (int i = 0; i < nums.size(); i++) {
		s.insert(nums[i]);
	}

	int ret = 0; 
	while (!s.empty()) {
		int lastNum = *(s.begin());
		s.erase(lastNum);
		int count = 1;
		int cur = lastNum + 1;
		while(s.find(cur) != s.end()) {
			count++;
			s.erase(cur);
			cur++;
		}
		cur = lastNum - 1;
		while(s.find(cur) != s.end()) {
			count++;
			s.erase(cur);
			cur--;
		}

		if (count > ret) {
			ret = count;
		}
	}

	return ret;
}