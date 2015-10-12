/*****************************
Spiral Matrix: https://leetcode.com/problems/spiral-matrix/

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order. 
For example,
Given the following matrix: 
[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5]. 
**/

//@time complexity: O(m * n)
//@space complexity: O(1)
//2A
vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> ret;
	if (matrix.size() <= 0 || matrix[0].size() <= 0) {
		return ret;
	}
	int row = matrix.size();
	int col = matrix[0].size();
	int cir = min((row+1)/2, (col+1)/2);

	for (int i = 0; i < cir; i++) {
		for (int up = i; up < col - i; up++) {
			ret.push_back(matrix[i][up]);
		}
		if (i + 1 > row - i - 1) {
			break;
		}
		for (int right = i + 1; right < row - i; right++) {
			ret.push_back(matrix[right][col - 1 - i]);
		}
		if (col - i - 2 < i) {
			break;
		}
		for (int down = col - i - 2; down >= i; down--) {
			ret.push_back(matrix[row - i - 1][down]);
		}
		for (int left = row - i - 2; left >= i + 1; left--) {
			ret.push_back(matrix[left][i]);
		}
	}

	return ret;
}