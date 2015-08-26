/************************
Summary Ranges: https://leetcode.com/problems/summary-ranges/

Given a sorted integer array without duplicates, return the summary of its ranges.
For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"]. 
**/

//time complexity: O(n)
//space complexity: o(1)
//2A: stringstream should be cleared when repeatedly used, otherwise, error would occur
vector<string> summaryRanges(vector<int>& nums) {
	vector<string> res;
	if (nums.size() <= 0) {
		return res;
	}

	int start = 0, end = 0;
	string s;
	stringstream ss;
	while (end < nums.size()) {
		if (nums[end] - nums[start] != end - start) {
			ss.clear();
			ss<<nums[start];
			ss>>s;

			if (end - 1 != start) {
				s += "->";
				ss.clear();
				ss<<nums[end-1];
				string tmp;
				ss>>tmp;
				s += tmp;
			}

			start = end;
			res.push_back(s);
			s.clear();
		}

		end++;
	}

	ss.clear();
	ss<<nums[start];
	ss>>s;
	if (end -1 != start) {
		s += "->";
		string tmp;
		ss.clear();
		ss<<nums[end-1];
		ss>>tmp;
		s += tmp;
	}
	res.push_back(s);

	return res;
}