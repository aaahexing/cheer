/**********************************
Gray Code: https://leetcode.com/problems/gray-code/

The gray code is a binary numeral system where two successive values differ in only one bit.
Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.
For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
**/

//@time complexity: O(2^n)
//@space complexity: O(1)
vector<int> grayCode(int n) {
    vector<int> ret;
    ret.push_back(0);
    if (n <= 0) {
        return ret;
    }
        
    ret.push_back(1);
        
    for (int i = 1; i < n; i++) {
        int tmp = 1 << i;
        for (int pos = ret.size() - 1; pos >= 0; pos--) {
            int cur = tmp + ret[pos];
            ret.push_back(cur);
        }
    }
        
    return ret;
}
