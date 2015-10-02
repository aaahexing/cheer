/************************************
Unique Binary Search Trees: https://leetcode.com/problems/unique-binary-search-trees/

Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
**/

//@time complexity: O(n)
//@space complexity: O(n^2)
int numTrees(int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 1;
    }
        
    vector<int> ret(n+1, 0);
    ret[0] = 1;
    ret[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= i-1; j++) {
            int numLeft = ret[j];
            int numRight = ret[i - j - 1];
            ret[i] += numLeft * numRight;
        }
    }
        
    return ret[n];
}
