/*************************
Factorial Trailing Zeroes : https://leetcode.com/problems/factorial-trailing-zeroes/

Given an integer n, return the number of trailing zeroes in n!.
Note: Your solution should be in logarithmic time complexity.
**/

//@desc: think clearly, then write
//@desc: this puzzle can be transformed into getting the total number of 5s in the factorial of n
//@time complexity: O(log5 n)
//@space complexity: O(1)
int trailingZeroes(int n) {
    int count = 0;
    int minPowOfFive = getMinPowerOfFive(n);
    for (int devisor = 5; devisor <= minPowOfFive; devisor *= 5) {
        count += n / devisor;
    }
        
    return count;
}
    
int getMinPowerOfFive(int n) {
    long long ret = 1;
    while (ret <= n) {
        ret *= 5;
    }
        
    return ret/5;
}
