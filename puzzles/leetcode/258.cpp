/*********
https://leetcode.com/problems/add-digits/
Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
For example:
Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
**/

//@time complexity: 
//@space complexity: O(1)
int addDigits(int num) {
    while (num / 10 > 0) {
        int digit = 0;
        while (num != 0) {
            digit += num % 10;
            num /= 10;
        }
        num = digit;
    }
        
    return num;
}
