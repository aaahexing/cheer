/**************************************
Maximal Square : https://leetcode.com/problems/maximal-square/

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area. 
For example, given the following matrix: 
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4. 
**/

//time complexity: O(m*n)
//space compleixty: O(m*n)
//2A: not understanding clearly of the puzzle caused the first failure....largest square not rectangle.......TT
int maximalSquare(vector<vector<char>>& matrix) {
	int row = matrix.size();
	if (row <= 0) {
		return 0;
	}

	int col = matrix[0].size();
	if (col <= 0) {
		return 0;
	}

	vector<vector<int>> height(row, vector<int>(col));
	for (int y = 0; y < row; y++) {
		for (int x = 0; x < col; x++) {
			height[y][x] = (matrix[y][x] == '0' ? 0 : (y > 0 ? 1 + height[y-1][x] : 1));
		}
	}

	stack<int> s;
	int maxArea = -1;

	for(int y = 0; y < row; y++) {
		for (int x = 0; x < col; x++) {
			while (!s.empty() && height[y][s.top()] > height[y][x]) {
				int top = s.top();
				s.pop();
				int width = s.empty() ? x : (x - s.top() -1);
				int tmpArea = (width <= height[y][top]) ? width * width : height[y][top] * height[y][top];
				if (tmpArea > maxArea) {
					maxArea = tmpArea;
				}
			}
			s.push(x);
		}

		while (!s.empty()) {
			int top = s.top();
			s.pop();

			int width = s.empty()? col : col - s.top() -1;
			int tmpArea = (width <= height[y][top]) ? width * width : height[y][top] * height[y][top];

			if (tmpArea > maxArea) {
				maxArea = tmpArea;
			}
		}
	}

	return maxArea;
}