/************************************
Rotate Image : https://leetcode.com/problems/rotate-image/

You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
Follow up:
 Could you do this in-place?
**/

//@time complexity: O(n^2)
//@space complexity: O(1)
//@1A
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() <= 0 || matrix[0].size() <= 0) {
            return ;
        }
        
        int n = matrix.size();
        for (int i = 0; i < (n + 1) / 2; i++) {
            for (int pos = i; pos < n - 1 - i; pos++) {
                //rotate the four position of A, B, C, D
                swap(matrix[i][pos], matrix[pos][n-1-i]);
                swap(matrix[i][pos], matrix[n-1-i][n-1-pos]);
                swap(matrix[i][pos], matrix[n-1-pos][i]);
            }
        }
    }
};