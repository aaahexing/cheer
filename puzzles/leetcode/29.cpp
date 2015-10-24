/*********************************************
Divide Two Integers : https://leetcode.com/problems/divide-two-integers/

Divide two integers without using multiplication, division and mod operator.
If it is overflow, return MAX_INT. 
**/

//@time complexity: O(logn) n is the result
//@space complexity: O(1)
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool positive = false;
        if ((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0)) {
            positive = true;
        }
        
        long long dividendNew = abs((long long) dividend);
        long long divisorNew = abs((long long) divisor);
        long long ret;
        
        if (divisor == 0) {
            return 0;
        }
        if (divisorNew == 1) {
            ret = positive ? dividendNew : -dividendNew;
            if (ret > INT_MAX) {
                return INT_MAX;
            } else {
                return ret;
            }
        }
        
        ret = 0;
        while (dividendNew >= divisorNew) {
            int i = 0;
            long long count = divisorNew << i;
            while (count <= dividendNew) {
                if (i == 0) {
                    i = 1;
                } else {
                    i = i << 1;
                }
                count = divisorNew << i;
            }
            i = i >> 1;
            count = divisorNew << i;
            dividendNew -= count;
            ret += (1 << i);
        }
        
        if (!positive) {
            ret = -ret;
        }
        
        return ret;
    }
};