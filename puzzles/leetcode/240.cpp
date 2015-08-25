/*************************
Search a 2D Matrix II: https://leetcode.com/problems/search-a-2d-matrix-ii/
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,
Consider the following matrix:
[
[1,   4,  7, 11, 15],
[2,   5,  8, 12, 19],
[3,   6,  9, 16, 22],
[10, 13, 14, 17, 24],
[18, 21, 23, 26, 30]
]
Given target = 5, return true.
Given target = 20, return false.
**/

//@time complexity: O(max(col, row))
//@space complexity: O(1)
//2A
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int row = matrix.size();
	if (row <= 0) {
		return false;
	}
	int col = matrix[0].size();
	if (col <= 0) {
		return false;
	}

	return searchMatrix(matrix, target, 0, col-1, 0, row-1);
}

bool searchMatrix(vector<vector<int>>& matrix, int target, int left, int right, int up, int down) {
	if (left > right || up > down) {
		return false;
	}

	if (target == matrix[up][right]) {
		return true;
	} else if(target < matrix[up][right]) {
		return searchMatrix(matrix, target, left, right-1, up, down);
	} else {
		return searchMatrix(matrix, target, left, right, up+1, down);
	}
}