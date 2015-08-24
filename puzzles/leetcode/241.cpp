/************
Different Ways to Add Parentheses : https://leetcode.com/problems/different-ways-to-add-parentheses/
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1 
Input: "2-1-1".
((2-1)-1) = 0
(2-(1-1)) = 2

Output: [0, 2]
**/

//@desc: should be familiar with he string function
//@time complexity: f(n) = 2 * (f(n-1) + f(n-2) + f(n-3) + ¡­¡­f(1))
//3A: string::find() return -1 when the input char can't be find; string::substr(pos, len)
vector<int> diffWaysToCompute(string input) {
	vector<int> res;
	res.clear();
	if (input.size() == 0) {
		return res;
	}

	int posAdd, posSub, posMul;
	posAdd = input.find('+');
	posSub = input.find('-');
	posMul = input.find('*');

	if (posAdd < 0 && posSub < 0 && posMul < 0) {
		res.push_back(atoi(input.c_str()));
		return res;
	}

	int pos = 0; 
	while(pos < input.size()) {
		posAdd = input.find('+', pos);
		posSub = input.find('-', pos);
		posMul = input.find('*', pos);

		if (posAdd < 0 && posSub < 0 && posMul < 0) {
			break;
		}

		int minPos;
		if (posAdd < 0 ) {
			if (posSub < 0) {
				minPos = posMul;
			} else {
				minPos = posMul < 0 ? posSub : min(posSub, posMul);
			}
		} else {
			if (posSub < 0) {
				minPos = posMul < 0 ? posAdd : min(posAdd, posMul);
			} else {
				minPos = posMul < 0 ? min(posAdd, posSub) : min(posAdd, min(posSub, posMul));
			}
		}

		vector<int> left = diffWaysToCompute(input.substr(0, minPos));
		vector<int> right = diffWaysToCompute(input.substr(minPos+1));

		for (int i = 0; i < left.size(); i++) {
			for (int j = 0; j < right.size(); j++) {
				if (minPos == posAdd) {
					res.push_back(left[i] + right[j]);
				} else if (minPos == posSub) {
					res.push_back(left[i] - right[j]);
				} else {
					res.push_back(left[i] * right[j]);
				}
			}
		}

		pos = minPos + 1;
	}

	return res;
}