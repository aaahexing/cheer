/***************************
Pascal's Triangle : https://leetcode.com/problems/pascals-triangle/

Given numRows, generate the first numRows of Pascal's triangle.
For example, given numRows = 5,
Return 
[
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
]
**/

//@time complexity: O(n^2)
//@space complexity: O(1)
//@1A
vector<vector<int>> generate(int numRows) {
	vector<vector<int>> triangle(numRows);
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				triangle[i].push_back(1);
			} else {
				triangle[i].push_back(triangle[i-1][j-1] + triangle[i-1][j]);
			}
		}
	}

	return triangle;
}