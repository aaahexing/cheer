#include <stack>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct point{
	int y;
	int xl, xr;
	point(int y, int xl, int xr){this->y = y; this->xl = xl; this->xr = xr;}
	point(void){xl = xr = y = 0;}
};

struct point  *board, start, end;

/*** node1 can jump to node2?
if can, return true; 
otherwise, return false
time complexity: O(1)  ***/
bool canJump(struct point node1, struct point node2)
{
	if(node2.y == node1.y + 1 && !(node1.xl >= node2.xr || node1.xr <= node2.xl))
		return true;
	return false;
}

//violent search; BFS(breadth-first search); test every availble node in the next depth and push in to stack; repeat
//space complexity: O(n)??? n nodes in the stack at most?
//time complexity：??? still can't understand
bool violentSearch(struct point * board, int n, struct point start, struct point end)
{
	struct point pt;
	stack<struct point> sta;
	sta.push(start);

	if(n < 0)
		return false;
	if(n == 0)
		return canJump(start, end);

	while(!sta.empty())  //for each node in the stack, O(n) time complexity will cost, but, how many nodes will be push in the stack? one node may be pushed in for many times? what is the total time complexity?
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
	bool * avail = (bool *)malloc(sizeof(bool) * (n+1));     //make whether board[i] can jump to the deeper depth, start from the start point, thus, n+1 space is needed
	memset(avail, true, sizeof(bool) * (n+1));
	sta.push(make_pair(start, 0));
	
	if(n < 0)
		return false;
	if(n == 0)
		return canJump(start, end);

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
	bool * avail = (bool *)malloc(sizeof(bool)*n);
	memset(avail,false,sizeof(bool)*n);
	int lastY = end.y;
	int pos;

	if(n < 0)
	{
		free(avail);
		return false;
	}
	if(n == 0)
	{
		free(avail);
		return canJump(start, end);
	}

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
				lastY--;
				break;
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

int main() {
    return 0;
}
