/***********************************************
Unique Paths : https://leetcode.com/problems/unique-paths/

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
How many possible unique paths are there?
**/

//@time complexity: O(m * n)
//@space complexity: O(m * n)
//@1A
//@in fact, this equals to C(m+n-2)(n-1)
int uniquePaths(int m, int n) {
	if (m == 0 || n == 0) {
		return 0;
	}
	vector<vector<int>> path(m, vector<int>(n));
	for (int i = m-1; i >= 0; i--) {
		for (int j = n-1; j >= 0; j--) {
			if (i == m - 1 && j == n - 1) {
				path[i][j] = 1;
			} else if (i == m - 1) {
				path[i][j] = path[i][j+1];
			} else if (j == n - 1) {
				path[i][j] = path[i+1][j];
			} else {
				path[i][j] = path[i+1][j] + path[i][j+1];
			}
		}
	}

	return path[0][0];
}