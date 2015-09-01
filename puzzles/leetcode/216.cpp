/***************************
Combination Sum III : https://leetcode.com/problems/combination-sum-iii/


Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
Ensure that numbers within the set are sorted in ascending order.
Example 1:
Input: k = 3, n = 7
Output: 
[[1,2,4]]
Example 2:
Input: k = 3, n = 9
Output: 
[[1,2,6], [1,3,5], [2,3,4]]
**/

//@desc: backtracking
//@time complexity: can't be calculated exactly
//@space complexity: O(1)
//3A: condition in line 40 being not considered suffiently caused the first failure. pop operation ommited in line 53 caused the second failure.... 
vector<vector<int>> combinationSum3(int k, int n) {
	vector<vector<int>> res;
	vector<int> tmp;
	if (k <= 0 || n <= 0) {
		return res;
	}
	combinationSum3(res, tmp, k, n);

	return res;
}

void combinationSum3(vector<vector<int>> &res, vector<int> tmp, int k, int n) {
	if (k == 1) {
		if (tmp.empty()) {
			if (n <= 9) {
				tmp.push_back(n);
				res.push_back(tmp);
			}
		} else {
			if (n > tmp[tmp.size()-1] && n <= 9) {
				tmp.push_back(n);
				res.push_back(tmp);
			}
		}

		return;
	}

	int i = tmp.empty() ? 1 : tmp[tmp.size()-1] + 1;
	for (; i <= n/2 && i <= 8; i++) {
		tmp.push_back(i);
		combinationSum3(res, tmp, k-1, n-i);
		tmp.pop_back();
	}
}