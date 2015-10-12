/**********************************************
Spiral Matrix II : https://leetcode.com/problems/spiral-matrix-ii/

Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
For example,
Given n = 3, 
You should return the following matrix: [
[ 1, 2, 3 ],
[ 8, 9, 4 ],
[ 7, 6, 5 ]
]
**/

//@time complexity: O(m * n)
//@space complexity: O(1)
//@1A
vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> ret(n, vector<int>(n));
	int start = 1;
	int col = n, row = n;
	for (int i = 0; i < (col + 1) / 2; i++) {
		for (int up = i; up <= col - 1 - i; up++) {
			ret[i][up] = start++;
		}
		if (i+1 > row - 1 - i) {
			break;
		}
		for (int right = i + 1; right <= row - 1 - i; right++) {
			ret[right][col - 1 - i] = start++;
		}
		if (col - 2 - i < i) {
			break;
		}
		for (int down = col - 2 - i; down >= i; down--) {
			ret[row - 1 - i][down] = start++;
		}
		for (int left = row - 2 - i; left >= i + 1; left--) {
			ret[left][i] = start++;
		}
	}

	return ret;
}