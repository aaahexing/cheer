/************************************
Valid Sudoku : https://leetcode.com/problems/valid-sudoku/

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
**/

//@time complexity: O(m * n)
//@space complexity: O(m + n)
//@1A
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) {
            return true;
        }
        unordered_set<char> s;
        //check everyRow
        for (int i = 0; i < board.size(); i++) {
            if (!checkRow(board, s, i)) {
                return false;
            }
        }
        
        //check everyCol
        for (int i = 0; i < board[0].size(); i++) {
            if (!checkCol(board, s, i)) {
                return false;
            }
        }
        
        //check every sub-box
        for (int i = 0; i < board.size(); i += 3) {
            for (int j = 0; j < board[i].size(); j += 3) {
                if (!checkSubbox(board, s, i, j)) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool checkRow(vector<vector<char>> & board, unordered_set<char> & s, int row) {
        s.clear();
        for (int i = 0; i < board[row].size(); i++) {
            if (board[row][i] >= '0' && board[row][i] <= '9') {
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
            if (board[i][col] >= '0' && board[i][col] <= '9') {
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
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if (board[i][j] >= '0' && board[i][j] <= '9') {
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