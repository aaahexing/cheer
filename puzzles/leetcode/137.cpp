/****************************
Single Number II : https://leetcode.com/problems/single-number-ii/

Given an array of integers, every element appears three times except for one. Find that single one. 
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory? 
**/

//@time complexity: O(32*n)
//@space complexity: O(32)
//@2A: be careful of negative integers since -1 >> 1 = -1, so, for loop of line 15-19 should be written as A[i] & (1<<pos) form.... 
int singleNumber(vector<int> & A) {
	int bits[32] = {0};
	for (int i = 0; i < A.size(); i++) {
		for (int pos = 0; pos < 32; pos++){
			if ((A[i] & (1 << pos)) != 0) {
				bits[pos]++;
			}
		}
	}

	int ret = 0;
	for (int i = 0; i < 32; i++) {
		if (bits[i] % 3 != 0) {
			ret = ret + (1<<i);
		}
	}

	return ret;
} 