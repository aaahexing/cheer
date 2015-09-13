/************************
Reverse Bits : https://leetcode.com/submissions/detail/39630857/

Reverse bits of a given 32 bits unsigned integer.
For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
Follow up:
If this function is called many times, how would you optimize it? 
**/

//time complexity: O(32)
//space complexity: O(1)
uint32_t reverseBits(uint32_t n) {
	uint32_t ret = 0;
	for (int i = 0; i < 32; i++) {
		ret <<= 1;
		if (n % 2 != 0) {
			ret += 1;
		}
		n >>= 1;
	}
	return ret;
}

