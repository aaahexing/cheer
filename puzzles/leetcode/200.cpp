/************************************
Number of Islands : https://leetcode.com/problems/number-of-islands/

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
Example 1:
11110
11010
11000
00000
Answer: 1
Example 2:
11000
11000
00100
00011
Answer: 3
**/

//--------------------------------------first solution---------------------------------------------------------
//@desc: DFS and BFS
//@time complexity: O(m*n)
//@space complexity: O(1)
int numIslands(vector<vector<char>>& grid) {
	int ret = 0;
	for (int y = 0; y < grid.size(); y++) {
		for (int x = 0; x < grid[y].size(); x++) {
			if (grid[y][x] == '1') {
				ret++;
				setWater(grid, y, x);
			}
		}
	}
	return ret;
}

void setWater(vector<vector<char>> & grid, int y, int x) {
	grid[y][x] = '0';
	if (x >= 1 && grid[y][x-1] == '1') {
		setWater(grid, y, x-1);
	}
	if (x+1 < grid[y].size() && grid[y][x+1] == '1') {
		setWater(grid, y, x+1);
	}
	if (y >= 1 && grid[y-1][x] == '1') {
		setWater(grid, y-1, x);
	}
	if (y+1 < grid.size() && grid[y+1][x] == '1') {
		setWater(grid, y+1, x);
	}
}

//--------------------------------------------------------second solution---------------------------------------------------------------
//@desc: union-set idea
//@time complexity: O(m*n)
//@space complexity: O(m*n)
int numIslands(vector<vector<char>>& grid) {
	int ret = 0;
	if (grid.size() <= 0) {
		return ret;
	}

	vector<int> unionSet(grid.size() * grid[0].size(), INT_MAX);
	int row = grid.size();
	int col = grid[0].size();

	for (int y = 0; y < row; y++) {
		for (int x = 0; x < col; x++) {
			if (grid[y][x] == '1') {
				int pos = y * col + x;
				unionSet[pos] = -1;
				if (x>= 1 && grid[y][x-1] == '1') {
					int pos2 = y * col + x - 1;
					unon(pos, pos2, unionSet);
				}
				if (y >= 1 && grid[y-1][x] == '1') {
					int pos2 = (y-1) * col + x;
					unon(pos, pos2, unionSet);
				}
			}
		}
	}

	for (int y = 0; y < row; y++) {
		for (int x = 0; x < col; x++) {
			if (unionSet[y * col + x] == -1) {
				ret++;
			}
		}
	}
	return ret;
}

int find(int pos, vector<int> & unionSet) {
	if(unionSet[pos] == -1) {
		return pos;
	}

	unionSet[pos] = find(unionSet[pos], unionSet);
	return unionSet[pos];
}

void unon(int pos1, int pos2, vector<int> & unionSet) {
	int ancestor1 = find(pos1, unionSet);
	int ancestor2 = find(pos2, unionSet);
	if (ancestor1 < ancestor2) {
		unionSet[ancestor2] = ancestor1;
	} 
	if (ancestor2 < ancestor1){
		unionSet[ancestor1] = ancestor2;
	}
}
