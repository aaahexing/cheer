/********************************
Sqrt(x): https://leetcode.com/problems/sqrtx/

Implement int sqrt(int x).
Compute and return the square root of x.
**/

//@time complexity: O(logn)
//@space complexity: O(1)
int mySqrt(int x) {
	int start = 0, end = x;
	int ret = 0;
	while (start <= end) {
		int mid = start + (end - start) / 2;
		unsigned long long square = (unsigned long long)mid * (unsigned long long)mid;
		if (square == x) {
			return mid;
		} else if (square < x) {
			if (mid > ret) {
				ret = mid;
			}
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}
	return ret;
}