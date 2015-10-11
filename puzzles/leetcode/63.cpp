/******************************************
Unique Paths II : https://leetcode.com/problems/unique-paths-ii/

Follow up for "Unique Paths":
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.
For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.
[
[0,0,0],
[0,1,0],
[0,0,0]
]
The total number of unique paths is 2.
**/

//@time complexity: O(m * n)
//@space complexity: O(m * n)
//@1A
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	if (obstacleGrid.size() <= 0 || obstacleGrid[0].size() <= 0) {
		return 0;
	}
	vector<vector<int>> path(obstacleGrid.size(), vector<int>(obstacleGrid[0].size()));
	for (int i = obstacleGrid.size() - 1; i >= 0; i--) {
		for (int j = obstacleGrid[i].size() - 1; j >= 0; j--) {
			if (obstacleGrid[i][j] == 1) {
				path[i][j] = 0;
			} else {
				if (i == obstacleGrid.size() - 1 && j == obstacleGrid[i].size() - 1) {
					path[i][j] = 1;
				} else if (i == obstacleGrid.size() - 1) {
					path[i][j] = path[i][j + 1];
				} else if (j == obstacleGrid[i].size() - 1) {
					path[i][j] = path[i + 1][j];
				} else {
					path[i][j] = path[i + 1][j] + path[i][j + 1];
				}
			}
		}
	}

	return path[0][0];
}