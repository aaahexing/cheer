/*********************************************
Plus One : https://leetcode.com/problems/plus-one/

Given a non-negative number represented as an array of digits, plus one to the number.
The digits are stored such that the most significant digit is at the head of the list.
**/

//@time complexity: O(n)
//@space complexity: O(1)
//@1A
vector<int> plusOne(vector<int>& digits) {
	int jinwei = 0;
	int sum, add;

	vector<int> ret;
	for (int i = digits.size() - 1; i >= 0; i--) {
		if (i == digits.size() - 1) {
			sum = digits[i] + 1;
		} else {
			sum = digits[i] + jinwei;
		}

		add = sum % 10;
		jinwei = sum / 10;
		ret.push_back(add);
	}

	if (jinwei) {
		ret.push_back(jinwei);
	}

	if (ret.size() >= 1) {
		reverse(ret.begin(), ret.end());
	}

	return ret;
}