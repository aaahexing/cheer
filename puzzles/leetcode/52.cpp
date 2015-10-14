/*********************************************
N-Queens II: https://leetcode.com/problems/n-queens-ii/

Follow up for N-Queens problem.
Now, instead outputting board configurations, return the total number of distinct solutions.
**/

//@backtracking
//@1A
class Solution {
public:
    int totalNQueens(int n) {
        int ret = 0;
        vector<int> pos;
        sloveNQueens(ret, pos, n);
        return ret;
    }
    
    void sloveNQueens(int & ret, vector<int> pos, int n) {
        if (pos.size() == n) {
            ret++;
            return;
        }
        
        string row(n, '.');
        for (int i = 0; i < n; i++) {
            if (collisionTest(pos, i)) {
                row[i] = 'Q';
                pos.push_back(i);
                sloveNQueens(ret, pos, n);
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