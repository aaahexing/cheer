/*************************************
Surrounded Regions : https://leetcode.com/problems/surrounded-regions/

Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region. 
For example,
X X X X
X O O X
X X O X
X O X X

After running your function, the board should be: 
X X X X
X X X X
X X X X
X O X X
**/

//@time complexity: O(n*m*log(n*m))
//@space complexity: O(n*m)
//@1A, little difficult to write
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size() <= 0 || board[0].size() <= 0) {
            return;
        }
        
        vector<int> unionset(board.size() * board[0].size(), INT_MAX);
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'O') {
                    int pos = i * board[i].size() + j;
                    unionset[pos] = -1;
                }
            }
        }
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'O') {
                    int pos1 = i * board[i].size() + j;
                    if (j - 1 >= 0 && board[i][j-1] == 'O') {
                        int pos2 = i * board[i].size() + j - 1;
                        unon(unionset, pos1, pos2);
                    }
                    if (i - 1 >= 0 && board[i-1][j] == 'O') {
                        int pos2 = (i - 1) * board[i-1].size() + j;
                        unon(unionset, pos1, pos2);
                    }
                }
            }
        }
        
        unordered_map<int, vector<int>> m; //m[i][0]: minLeft, m[i][1]: maxRight, m[i][2]: minTop, min[i][3]: minBottom
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'O') {
                    int pos = i * board[i].size() + j;
					int root = find(unionset, pos);
                    if (m[root].size() <= 0){
                        m[root].push_back(j);
                        m[root].push_back(j);
                        m[root].push_back(i);
                        m[root].push_back(i);
                    } else {
						if (j < m[root][0]) {
							m[root][0] = j;
						}
						if (j > m[root][1]) {
							m[root][1] = j;
						}
						if (i < m[root][2]) {
							m[root][2] = i;
						}
						if (i > m[root][3]) {
							m[root][3] = i;
						}
					}
				}
			}
		}
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'O') {
                    int pos = i * board[i].size() + j;
					int root = find(unionset, pos);
                    if (m[root][0] > 0 && m[root][1] < board[i].size() -1 && m[root][2] > 0 && m[root][3] < board.size() -1) {
                        board[i][j] = 'X';
                    }
                }
            }
        }        
    }
    
    void unon(vector<int> & unionset, int root1, int root2) {
        root1 = find(unionset, root1);
        root2 = find(unionset, root2);
        if (root1 < root2) {
            unionset[root2] = root1;
        } else if (root2 < root1) {
            unionset[root1] = root2;
        }
    }
    
    int find(vector<int> & unionset, int pos) {
        if (unionset[pos] == -1) {
            return pos;
        }
        
        unionset[pos] = find(unionset, unionset[pos]);
		return unionset[pos];
    }
};