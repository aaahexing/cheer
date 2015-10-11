/******************************************
Minimum Path Sum : https://leetcode.com/problems/minimum-path-sum/

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
**/

//@time complexity: O(m * n)
//@space complexity: O(m * n)
//@1A
int minPathSum(vector<vector<int>>& grid) {
	if (grid.size() <= 0 || grid[0].size() <= 0) {
		return 0;
	}
	vector<vector<int>> step(grid.size(), vector<int>(grid[0].size()));
	for (int i = grid.size() - 1; i >= 0; i--) {
		for (int j = grid[i].size() - 1; j >= 0; j--) {
			if (i == grid.size() - 1 && j == grid[i].size() - 1) {
				step[i][j] = grid[i][j];
			} else if (i == grid.size() - 1) {
				step[i][j] = step[i][j+1] + grid[i][j];
			} else if (j == grid[i].size() - 1) {
				step[i][j] = step[i+1][j] + grid[i][j];
			} else {
				step[i][j] = min(step[i+1][j], step[i][j+1]) + grid[i][j];
			}
		}
	}

	return step[0][0];
}