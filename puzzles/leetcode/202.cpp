/***************************************
Happy Number : https://leetcode.com/problems/happy-number/

Write an algorithm to determine if a number is "happy".
A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
Example: 19 is a happy number
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
**/

//1A
//space time complexity and time complexity can't be evaluated....
bool isHappy(int n) {
	unordered_set<int> sum;
	sum.insert(n);
	while (true) {
		n = countSum(n);
		if (n == 1) {
			return true;
		} else {
			pair<unordered_set<int>::iterator, bool> ret = sum.insert(n);
			if (!ret.second) {
				return false;
			}
		}
	}
}

int countSum(int n) {
	int sum = 0;
	while (n) {
		int digit = n % 10;
		sum += digit * digit;
		n /= 10;
	}
	return sum;
}