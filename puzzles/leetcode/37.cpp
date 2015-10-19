/**********************************************
Sudoku Solver : https://leetcode.com/problems/sudoku-solver/

Write a program to solve a Sudoku puzzle by filling the empty cells.
Empty cells are indicated by the character '.'.
You may assume that there will be only one unique solution. 
**/

//@backtracking
//@time complexity: O(9^(m * n)) at most
//@space complexity: O(max(m, n))
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        unordered_set<char> s;
        solveSudoku(board, s, 0, 0);
    }
private:
    bool solveSudoku(vector<vector<char>>& board, unordered_set<char> s, int row, int col) {
        if (board[row][col] == '.') {
            for (int i = 1; i <= 9; i++) {
                board[row][col] = char(i + '0');
                if (checkRow(board, s, row) && checkCol(board, s, col) && checkSubbox(board, s, row/3, col/3)) {
                    if (row == board.size() - 1 && col == board[row].size() - 1) {
                        return true;
                    } else if (col == board[row].size() - 1) {
                        if (solveSudoku(board, s, row + 1, 0)) {
                            return true;
                        }
                    } else {
                        if (solveSudoku(board, s, row, col + 1)) {
                            return true;
                        }
                    }
                }
            }
            board[row][col] = '.';
        } else {
            if (row == board.size() - 1 && col == board[row].size() - 1) {
                return true;
            } else if (col == board[row].size() - 1) {
                return solveSudoku(board, s, row + 1, 0);
            } else {
                return solveSudoku(board, s, row, col + 1);
            }
        }
        
        return false;
    }
    
    bool checkRow(vector<vector<char>> & board, unordered_set<char> & s, int row) {
        s.clear();
        for (int i = 0; i < board[row].size(); i++) {
            if (board[row][i] >= '1' && board[row][i] <= '9') {
                if (s.find(board[row][i]) != s.end()) {
                    return false;
                } else {
                    s.insert(board[row][i]);
                }
            }
        }
        return true;
    }
    
    bool checkCol(vector<vector<char>> & board, unordered_set<char> & s, int col) {
        s.clear();
        for (int i = 0; i < board.size(); i++) {
            if (board[i][col] >= '1' && board[i][col] <= '9') {
                if (s.find(board[i][col]) != s.end()) {
                    return false;
                } else {
                    s.insert(board[i][col]);
                }
            }
        }
        return true;
    }
    
    bool checkSubbox(vector<vector<char>> & board, unordered_set<char> & s, int row, int col) {
        s.clear();
        for (int i = 3 * row; i < 3 * row + 3; i++) {
            for (int j = 3 * col; j < 3 * col + 3; j++) {
                if (board[i][j] >= '1' && board[i][j] <= '9') {
                    if (s.find(board[i][j]) != s.end()) {
                        return false;
                    } else {
                        s.insert(board[i][j]);
                    }
                }
            }
        }
        return true;
    }
};