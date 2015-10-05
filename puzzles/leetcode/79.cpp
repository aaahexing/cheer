/****************************************
Word Search: https://leetcode.com/problems/word-search/

Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
For example,
Given board =
[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
**/

//@backtracking
//@2A
class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        if (word.size() <= 0) {
            return true;
        }
        if (board.size() <= 0 || board[0].size() <= 0) {
            return false;
        }

        vector<vector<bool> > path(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    path[i][j] = true;
                    if (checkAvail(board, word, path, i, j)) {
                        return true;
                    }
                    path[i][j] = false;
                }
            }
        }

        return false;
    }

    bool checkAvail(vector<vector<char> >& board, string word, vector<vector<bool> >& path, int i, int j) {
        if (word.size() == 1) {
            return true;
        }

        for (int dir = 0; dir < 4; dir++) { //dir == 0: left; dir == 1: right; dir == 2: up; dir == 3
            if ((dir == 0 && j == 0) || (dir == 1 && j == board[0].size() - 1) || (dir == 2 && i == 0) || (dir == 3 && i == board.size() - 1)) {
                continue;
            }

            if (dir == 0 && path[i][j - 1] == false && board[i][j - 1] == word[1]) {
                path[i][j - 1] = true;
                if (checkAvail(board, word.substr(1), path, i, j - 1)) {
                    return true;
                }
                path[i][j - 1] = false;
            }

            if (dir == 1 && path[i][j + 1] == false && board[i][j + 1] == word[1]) {
            	path[i][j + 1] = true;
                if (checkAvail(board, word.substr(1), path, i, j + 1)) {
                    return true;
                }
                path[i][j + 1] = false;
            }

            if (dir == 2 && path[i - 1][j] == false && board[i - 1][j] == word[1]) {
                path[i - 1][j] = true;
                if (checkAvail(board, word.substr(1), path, i - 1, j)) {
                    return true;
                }
                path[i - 1][j] = false;
            }

            if (dir == 3 && path[i + 1][j] == false && board[i + 1][j] == word[1]) {
                path[i + 1][j] = true;
                if (checkAvail(board, word.substr(1), path, i + 1, j)) {
                    return true;
                }
                path[i + 1][j] = false;
            }
        }

        return false;
    }
};
