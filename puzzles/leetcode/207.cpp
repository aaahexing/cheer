/******************
Course Schedule: https://leetcode.com/problems/course-schedule/

There are a total of n courses you have to take, labeled from 0 to n - 1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses? 
For example:
2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
**/

//time complexity: O(n^3)
//space complexity: O(n^2)
//time limit exceeded
bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
	if (numCourses <= 1) {
		return true;
	}

	vector<vector<int> > matrix(numCourses, vector<int>(numCourses)); //matrix[i][j] equal to 1 means j must be taken before i
	for (int i = 0; i < numCourses; i++) {
		for (int j = 0; j < numCourses; j++) {
			matrix[i][j] = 0;
		}
	}

	createMatrix(matrix, prerequisites);
	return judge(matrix);
}

void createMatrix(vector<vector<int>> & matrix, vector<pair<int, int>> & prerequisities) {
	for (int i = 0; i < prerequisities.size(); i++) {
		matrix[prerequisities[i].first][prerequisities[i].second] = 1;
	}

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			if (matrix[i][j] == 1) {
				for (int k = 0; k < matrix[j].size(); k++) {
					if (matrix[j][k] == 1) {
						matrix[i][k] = 1;
					}
				}
			}
		}
	}
}

bool judge(vector<vector<int>> & matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.size(); j++) {
			if (matrix[i][j] == 1 && matrix[j][i] == 1) {
				return false;
			}
		}
	}

	return true;
}
