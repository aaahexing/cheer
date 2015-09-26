/*********************************
Triangle : https://leetcode.com/problems/triangle/

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
For example, given the following triangle
[
[2],
[3,4],
[6,5,7],
[4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11). 
**/

//@time complexity: O(n^2)
//@space complexity: O(n)
//@1A
int minimumTotal(vector<vector<int>>& triangle) {
	if (triangle.size() <= 0) {
		return 0;
	}
	vector<int> minimumPath(triangle.size());
	for (int i = triangle.size() - 1; i >= 0; i--) {
		for (int j = 0; j <= i; j++) {
			if (i == triangle.size() - 1) {
				minimumPath[j] = triangle[i][j];
			}
			else {
				minimumPath[j] = triangle[i][j] + (minimumPath[j] < minimumPath[j+1] ? minimumPath[j] : minimumPath[j+1]);
			}
		}
	}

	return minimumPath[0];
}