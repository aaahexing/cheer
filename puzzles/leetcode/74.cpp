/*******************************
Search a 2D Matrix: https://leetcode.com/problems/search-a-2d-matrix/

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,
Consider the following matrix:
[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
**/

//@time complexity: O(logn)
//@space complexity: O(1)
//@1A
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.size() <= 0 || matrix[0].size() <= 0) {
        return false;
    }
        
    int row = matrix.size();
    int col = matrix[0].size();
    int startIdx = 0;
    int endIdx = (row - 1) * col + (col - 1);
    while (startIdx <= endIdx) {
        int midIdx = startIdx + (endIdx - startIdx)/2;
        int i = midIdx / col;
        int j = midIdx % col;
        if (matrix[i][j] == target) {
            return true;
        } else if (matrix[i][j] < target) {
            startIdx = midIdx + 1;
        } else {
            endIdx = midIdx - 1;
        }
    }
        
    return false;
}
