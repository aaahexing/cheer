/**********************************
N-Queens : https://leetcode.com/problems/n-queens/

The n-queens puzzle is the problem of placing n queens on an n¡Án chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
For example,
 There exist two distinct solutions to the 4-queens puzzle:
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],
 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
**/

//@backtracking
//@1A
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        if (n <= 0) {
            return ret;
        }
        vector<int> pos;
        vector<string> slt;
        sloveNQueens(ret, slt, pos, n);
        return ret;
    }
    
    void sloveNQueens(vector<vector<string>> & ret, vector<string> slt, vector<int> pos, int n) {
        if (pos.size() == n) {
            ret.push_back(slt);
            return;
        }
        
        string row(n, '.');
        for (int i = 0; i < n; i++) {
            if (collisionTest(pos, i)) {
                row[i] = 'Q';
                slt.push_back(row);
                pos.push_back(i);
                sloveNQueens(ret, slt, pos, n);
                slt.pop_back();
                row[i] = '.';
                pos.pop_back();
            }
        }
    }
    
    //return true if no collision is found, otherwise return false
    bool collisionTest(vector<int> pos, int i) {
        if (pos.size() <= 0) {
            return true;
        }
        
        int j = pos.size();
        for (int k = 0; k < pos.size(); k++) {
            int x1 = pos[k];
            if (isCollide(x1, k, i, j)) {
                return false;
            }
        }
        return true;
    }
    
    //return true if (x1, y1) collide with (x2,y2), otherwise return false
    bool isCollide(int x1, int y1, int x2, int y2) {
        if (x1 == x2 || y1 == y2 || (y2 - y1 == x2 - x1) || (y2 - y1 == x1 - x2)) {
            return true;
        } else {
            return false;
        }
    }
};