#include <stack>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct point{
	int y;
	int xl, xr;
	point(int y, int xl, int xr)
	{
		this->y = y; 
		this->xl = xl; 
		this->xr = xr;
	}
	point(void)
	{
		xl = xr = y = 0;
	}
};

struct point  *board, start, end;

/*** node1 can jump to node2?
if can, return true; 
otherwise, return false
time complexity: O(1)  ***/
bool canJump(const struct point & node1, const struct point & node2)
{
	if(node2.y == node1.y + 1 && !(node1.xl >= node2.xr || node1.xr <= node2.xl))
		return true;
	return false;
}

//violent search; DFS(depth-first search); test every availble node in the next depth and push in to stack; repeat
//space complexity: O(n) stack
//time complexity：O(n!) full array...
bool violentSearch(struct point * board, int n, const struct point & start, const struct point & end)
{
	struct point pt;
	stack<struct point> sta;
	sta.push(start);

	if(n < 0)
		return false;
	if(n == 0)
		return canJump(start, end);

	while(!sta.empty())  //for each node in the stack, O(n) time complexity will cost, the node in the stack is the n nodes full array at most...
	{
		pt = sta.top();
		sta.pop();
		for(int i=0; i<n; i++)       //O(n) time complexity
		{
			if(canJump(pt, board[i]))
			{
				if(canJump(board[i], end))
					return true;
				sta.push(board[i]);
			}
		}
	}

	return false;
}

//BFS, but mideum result is recorded and used to redece some repeat operation
//time complexity: 不是O(n^2)啊，因为，对于能跳到上一层的木板，它有可能多次的入栈，从而，导致入栈的木板个数，并不是n，整体时间复杂度也不是O(n^2)
//space complexity: O(n)跟上一个一样
//与上一方法对比的话，整体时间复杂度有一定的节省，但空间复杂度还是相同数量级的，但无法节省到O(n^2).....
bool mediumSearch(struct point * board, int n, struct point start, struct point end)
{
	struct point pt;
	int index;
	stack<pair<struct point, int> > sta;
	bool * avail;
	
	if(n < 0)
		return false;
	if(n == 0)
		return canJump(start, end);
		
	avail = (bool *)malloc(sizeof(bool) * (n+1));     //make whether board[i] can jump to the deeper depth, start from the start point, thus, n+1 space is needed
	memset(avail, true, sizeof(bool) * (n+1));
	sta.push(make_pair(start, 0));

	while(!sta.empty())
	{
		pt = sta.top().first;
		index = sta.top().second;
		sta.pop();
		bool temp = false;
		
		for(int i=0; i<n; i++)
		{
			if(canJump(pt, board[i]))
			{
				temp = true;
				if(canJump(board[i],end))
					return true;
				if(avail[i+1])
					sta.push(make_pair(board[i], i+1));
			}
		}

		avail[index] = temp;
	}

	free(avail);
	avail = NULL;

	return false;
}

bool cmp(struct point node1, struct point node2)
{
	if(node1.y < node2.y)
		return 1;
}

//这个复杂度只有O(n^2）,因为，最多n个数进行for循环，空间复杂度，O（n)
bool fastSearch(struct point * board, int n, struct point start, struct point end)
{
	sort(board,board+n, cmp);
	bool * avail;
	int lastY = end.y;
	int pos;

	if(n < 0)
		return false;
	if(n == 0)
		return canJump(start, end);
	
	avail = (bool *)malloc(sizeof(bool)*n);
	memset(avail,false,sizeof(bool)*n);

	for(pos = n-1; pos>=0; pos--)
	{
		if(board[pos].y != lastY-1)
		{
			lastY--;
			break;
		}
		else if(canJump(board[pos],end))
			avail[pos] = true;
	}

	for(; pos >= 0; pos--)
	{
		while(true)
		{
			if(board[pos].y != lastY - 1)
			{
				if(board[pos].y != lastY - 2)
				{
					free(avail);
					return false;               // lastY - 1 coordinates doesn't exit, so return false 
				}
				else
				{
					lastY--;
					break;
				}
			}
			else
			{
				for(int i=0; i<n; i++)
				{
					if(canJump(board[pos],board[i]) && avail[i])
						avail[pos] = 1;
				}
			}
		}
	}

	for(int i=0; i<n; i++)
		if(canJump(start,board[i]) && avail[i])
		{
			free(avail);
			return true;
		}

	free(avail);
	return false;
}

// key recursive function in Function recursiveSearch
// judge whether the frog can jump from board[pos-1] to end, if can, return true
// scope of pos is 0 to n, since we count from the start point to board[n-1] 
bool recursiveSearchKey(struct point * board, int n, int pos, struct point start, struct point end)
{
	if(canJump(start, end))
		return true;
		
	bool res = false;
	for(int i=0; i<n; i++)
	{
		if(canJump(start, board[i]) && avail[i+1])
		{
			res = recursiveSearchKey(board, n, i+1, board[i], end); // update the start point
			if(res)
				return true;
		}
	}
	
	if(!res)
		avail[pos] = false;
	
	return false;
}

//to do frog jumping puzzle recursively
//if the frog can jump from start to end, return true
//time complexity: same as the mediumSearch
//space complexity: O(n)
bool recursiveSearch(struct point * board, int n, struct point start, struct point end)
{
	if(n < 0)
		return false;
	if(n == 0)
		return canJump(start, end);
		
	bool * avail = (bool *)malloc(sizeof(bool) * (n+1));
	memset(avail, true, sizeof(bool) * (n+1));
	bool res = recursiveSearchKey(board, n, 0, start, end);
	
	free(avail);
	return res;
}

// Complete implementation.
enum StatusEnum {
    UNKNOWN,
    CAN_BE_REACHED,
    CANNOT_BE_REACHED
};

// Keywords: memorize search(similar to DP)
// "记忆化搜索" in Chinese.
StatusEnum dfs(int board_index, const vector<Point>& board, const Point& end, vector<StatusEnum>& status) {
    if (status[board_index] != UNKNOWN) {
        return status[board_index];
    }
    const int n = board.size();
    status[board_index] = CANNOT_BE_REACHED;
    if (canJump(board[board_index], end)) {
        status[board_index] = CAN_BE_REACHED;
    }
    for (int i = 0; i < n && status[board_index] != CAN_BE_REACHED; ++i) {
        if (status[]canJump(board[board_index], board[i])) {
            if (dfs(i, board, end, status) == CAN_BE_REACHED) {
                status[board_index] = CAN_BE_REACHED;
            }
        }
    }
    return status[board_index];
}

bool CanReach(const Point& start, const Point& end, vector<Point> board) {
    // No sort needed.
    board.push_back(start);
    const int n = board.size();
    vector<StatusEnum> status(n);
    for (int i = 0; i < n; ++i) {
        status[i] = UNKNOWN;
    }
    return dfs(0, board, end, status) == CAN_BE_REACHED;
}

int main() {
    return 0;
}
