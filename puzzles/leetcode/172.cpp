/*************************
Factorial Trailing Zeroes : https://leetcode.com/problems/factorial-trailing-zeroes/

Given an integer n, return the number of trailing zeroes in n!.
Note: Your solution should be in logarithmic time complexity.
**/

//wrong
int trailingZeroes(int n) {
	if (n <= 0) {
		return 0;
	}
	int digit = getDigit(n);
	int minVal = getMinValInDigitN(digit);

	int ret = (n / minVal) * (digit - 1 + trailingZeroes(minVal - 1)) + trailingZeroes(n - n / minVal * minVal) + ((n / minVal) >= 5 ? 1 : 0);
	return ret;
}

int getDigit(int n) {
	if (n < 10) {
		return 1;
	}
	return getDigit(n/10) + 1;
}

int getMinValInDigitN(int digit) {
	if (digit == 1) {
		return 1;
	} 
	return getMinValInDigitN(digit - 1) * 10;
