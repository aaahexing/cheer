/*****************************************
Maximal Rectangle: https://leetcode.com/problems/maximal-rectangle/

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
**/

//@time complexity: O(row * col)
//@space complexity: O(row * col);
int maximalRectangle(vector<vector<char>>& matrix) {
    int row = matrix.size();
    int ret = 0;
    if (row <= 0) {
        return 0;
    }
    int col = matrix[0].size();
    if (col <= 0) {
        return 0;
    }
    vector<vector<int>> height(row, vector<int>(col));
    stack<int> s;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == 0) {
                height[i][j] = (matrix[i][j] == '1' ? 1 : 0);
            } else {
                height[i][j] = (matrix[i][j] == '1' ? 1 + height[i-1][j] : 0);
            }
        }
    }
        
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (s.empty()) {
                s.push(j);
            } else {
                if (height[i][j] < height[i][s.top()]) {
                    while(!s.empty() && height[i][s.top()] > height[i][j]) {
                        int top = s.top();
                        int tmpArea;
                        s.pop();
                        if (s.empty()) {
                            tmpArea = height[i][top] * j;
                        } else {
                            tmpArea = height[i][top] * (j - s.top() - 1);
                        }
                        if (tmpArea > ret) {
                            ret = tmpArea;
                        }
                    }
                }
                s.push(j);
            }
        }
            
        while (!s.empty()) {
            int tmpArea;
            int top = s.top();
            s.pop();
            if (s.empty()) {
                tmpArea = height[i][top] * col;
            } else {
                tmpArea = height[i][top] * (col - s.top() - 1);
            }
                
            if (tmpArea > ret) {
                ret = tmpArea;
            }
        }
    }
        
    return ret;
}
