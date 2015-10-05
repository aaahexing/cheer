/********************************
Set Matrix Zeroes: https://leetcode.com/problems/set-matrix-zeroes/

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
**/

//@time complexity: O(m*n)
//@space complexity: O(1)
//@2A
void setZeroes(vector<vector<int>>& matrix) {
    if (matrix.size() <= 0 || matrix[0].size() <= 0) {
        return ;
    }
        
    bool zeroRow = false;
    bool zeroCol = false;
    for (int j = 0; j < matrix[0].size(); j++) {
        if (matrix[0][j] == 0) {
            zeroRow = true;
            break;
        }
    }
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[i][0] == 0) {
            zeroCol = true;
            break;
        }
    }
        
    for (int i = 1; i < matrix.size(); i++) {
        for (int j = 1; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 0) {
                for (int m = 0; m < j; m++) {
                    matrix[i][m] = 0;
                }
                for (int m = 0; m < i; m++) {
                    matrix[m][j] = 0;
                }
            }
        }
    }
        
    for (int j = 1; j < matrix[0].size(); j++) {
        if (matrix[0][j] == 0) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][j] = 0;
            }
        }
    }
        
    for (int i = 1; i < matrix.size(); i++) {
        if (matrix[i][0] == 0) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[i][j] = 0;
            }
        }
    }
        
    if (zeroCol) {
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i][0] = 0;
        }
    }
    if (zeroRow) {
        for (int j = 0; j < matrix[0].size(); j++) {
            matrix[0][j] = 0;
        }
    }
}
