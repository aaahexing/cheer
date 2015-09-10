/*******************************
Bitwise AND of Numbers Range: https://leetcode.com/problems/bitwise-and-of-numbers-range/

Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
For example, given the range [5, 7], you should return 4. 
**/

//time complexity: O(1)
//space complexity: O(1)
//2A : missing the recursive part in line 24 caused the first failure
int rangeBitwiseAnd(int m, int n) {
	if (m == 0) {
		return 0;
	}

	if (m == n) {
		return m;
	}

	int len1 = bitLength(m);
	int len2 = bitLength(n);
	if (len1 == len2) {
		int leastNum = 1 << (len1 - 1);
		return leastNum + rangeBitwiseAnd(m - leastNum, n - leastNum);
	} else {
		return 0;
	}
}

int bitLength(int k) {
	int length = 0;
	while (k) {
		length++;
		k >>= 1;
	}
	return length;
}