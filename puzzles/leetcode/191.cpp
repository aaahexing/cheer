/*********************
Number of 1 Bits : https://leetcode.com/problems/number-of-1-bits/

Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
**/

//time complexity: O(l)
//l is the pos of the most significant bit '1'
int hammingWeight(uint32_t n) {
    int ret = 0;
    while (n) {
        if (n % 2 != 0) {
            ret++;
        }
        n >>= 1;
    }
    return ret;
}
