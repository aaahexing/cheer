/**************************************
Permutation Sequence : https://leetcode.com/problems/permutation-sequence/

The set [1,2,3,бн,n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order,
 We get the following sequence (ie, for n = 3): 
1."123"
2."132"
3."213"
4."231"
5."312"
6."321"
Given n and k, return the kth permutation sequence.
**/

//@time complexity: O(n)
//@space complexity: O(1)
class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        for (int i = 1; i <= n; i++) {
            s += char('0' + i);
        }
        return getPermutation(s, k);
    }
    
    string getPermutation(string s, int k) {
        if (k == 1) {
            return s;
        }
        
        string ret;
        int factor = jieCheng(s.size() - 1);
        for (int i = 0; i < s.size(); i++) {
            if (k <= factor) {
                ret = s[i];
                s.erase(i, 1);
                ret += getPermutation(s, k);
                return ret;
            } else {
                k = k - factor;
            }
        }
    }
    
    int jieCheng(int n) {
        int ret = 1;
        for (int i = 1; i <= n; i++) {
            ret = ret * i;
        }
        
        return ret;
    }
};