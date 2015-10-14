/*************************************
Pow(x, n) : https://leetcode.com/problems/powx-n/

Implement pow(x, n). 
**/

//@time complexity: O(log n)
//@space complexity: O(1)
//@2A: the recursive one should be long long type, be careful of the minimum integer
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) {
            return 0;
        }
        
        if (n < 0) {
            x = 1 / x;
            return myPowPositive(x, -(long long)n);
        } else if (n == 0) {
            return 1;
        } else {
            return myPowPositive(x, n);
        }
        
    }
    
    //@desc: in this function, in power factor n is a positive integer
    double myPowPositive(double x, long long n) {
        if (n == 1) {
            return x;
        }
        
        double tmp = myPowPositive(x, n/2);
        if (n % 2 == 0) {
            return tmp * tmp;
        } else {
            return tmp * tmp * x;
        }
    }
};