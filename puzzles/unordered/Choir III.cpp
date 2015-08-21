#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

//first solution
//time compelxity: O(m*n^2)
//space complexity: O(m*n)
//5A
int choirChoose(vector<vector<int> > & choirVal, vector<vector<int> > & sexVal, int n, int m, int b, int g){
	vector<vector<int> > sumVal(n, vector<int>(m));     //sumVal(i,j) means the sum of choir value in rectangle [0-i][0-j]
	vector<vector<int> > sumBoy(n, vector<int>(m));     //sumBoy(i,j) means the sum  of boy in rectangle [0-i][0-j]
	vector<vector<int> > sumGirl(n, vector<int>(m));    //sumGirl(i,j) means the sum of girl in rectangle [0-i][0-j]
	vector<vector<int> > notAvail(n, vector<int>(m));   //notAvail(i, j) means the num of people can sing the song in rectangle[0-i][0-j]

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int leftVal, upVal, leftUpVal;
			int leftBoy, upBoy, leftUpBoy;
			int leftGirl, upGirl, leftUpGirl;
			int leftNotAvail, upNotAvail, leftUpNotAvail;

			upVal = i > 0 ? sumVal[i-1][j] : 0;
			upBoy = i > 0 ? sumBoy[i-1][j] : 0;
			upGirl = i > 0 ? sumGirl[i-1][j] : 0;
			upNotAvail = i > 0 ? notAvail[i-1][j] : 0;

			leftVal = j > 0 ? sumVal[i][j-1] : 0;
			leftBoy = j > 0 ? sumBoy[i][j-1] : 0;
			leftGirl = j > 0 ? sumGirl[i][j-1] : 0;
			leftNotAvail = j > 0 ? notAvail[i][j-1] : 0;

			leftUpVal = i > 0 && j > 0 ? sumVal[i-1][j-1] : 0;
			leftUpBoy = i > 0 && j > 0 ? sumBoy[i-1][j-1] : 0;
			leftUpGirl = i > 0 && j > 0 ? sumGirl[i-1][j-1] : 0;
			leftUpNotAvail = i > 0 && j > 0 ? notAvail[i-1][j-1] : 0;

			sumVal[i][j] = leftVal + upVal - leftUpVal + choirVal[i][j];
			sumBoy[i][j] = leftBoy + upBoy - leftUpBoy + (sexVal[i][j] == 1 ? 1 : 0);
			sumGirl[i][j] = leftGirl + upGirl - leftUpGirl + (sexVal[i][j] == 2 ? 1 : 0);
			notAvail[i][j] = leftNotAvail + upNotAvail - leftUpNotAvail + (choirVal[i][j] < 0 ? 1 : 0);
			
		}
	}

	int res = -1;
	int tempSum, tempBoy, tempGirl, colNotAvail;

	int i, ii, j, jj;
	for(i = 0; i < n; i++){
		for(ii = i; ii < n; ii++){
			for(j = 0, jj = j; jj < m; jj++){
				int leftVal, upVal, leftUpVal;
				int leftBoy, upBoy, leftUpBoy;
				int leftGirl, upGirl, leftUpGirl;
				int leftColNotAvail, upColNotAvail, leftUpColNotAvail;

				upVal = i > 0 ? sumVal[i-1][jj] : 0;
				upBoy = i > 0 ? sumBoy[i-1][jj] : 0;
				upGirl = i > 0 ? sumGirl[i-1][jj] : 0;
				upColNotAvail = i > 0 ? notAvail[i-1][jj] : 0;

				leftVal = j > 0 ? sumVal[ii][j-1] : 0;
				leftBoy = j > 0 ? sumBoy[ii][j-1] : 0;
				leftGirl = j > 0 ? sumGirl[ii][j-1] : 0;
				leftColNotAvail = jj > 0 ? notAvail[ii][jj-1] : 0;

				leftUpVal = i > 0 && j > 0 ? sumVal[i-1][j-1] : 0;
				leftUpBoy = i > 0 && j > 0 ? sumBoy[i-1][j-1] : 0;
				leftUpGirl = i > 0 && j > 0 ? sumGirl[i-1][j-1] : 0;
				leftUpColNotAvail = i > 0 && jj > 0 ? notAvail[i-1][jj-1] : 0;

				tempSum = sumVal[ii][jj] + leftUpVal - leftVal - upVal;
				tempBoy = sumBoy[ii][jj] + leftUpBoy - leftBoy - upBoy;
				tempGirl = sumGirl[ii][jj] + leftUpGirl - leftGirl - upGirl;
				colNotAvail = notAvail[ii][jj] + leftUpColNotAvail - leftColNotAvail - upColNotAvail;

				if(colNotAvail > 0){
					j = jj + 1;
					continue;
				}

				if(tempBoy < b || tempGirl < g){
					continue;
				}

				if(tempSum > res)
					res = tempSum;
			}
		}
	}

	return res;
}

int main()
{
	int n, m, b, g;
	while(cin>>n>>m>>b>>g){
		vector<vector<int> > choirVal(n, vector<int>(m));
		vector<vector<int> > sexVal(n, vector<int>(m));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin>>choirVal[i][j];
				cin>>sexVal[i][j];
			}
		}

		int res = choirChoose(choirVal, sexVal, n, m, b, g);
		if(res < 0)
			cout<<"No solution!"<<endl;
		else
			cout<<res<<endl;
	}

}

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

//time compelxity: O(m*n)
//space complexity: O(m*n)
//many times
int choirVal[100][2000] = {0};
int sexVal[100][2000] = {0};
int sumVal[100][2000] = {0};
int sumBoy[100][2000] = {0};
int sumGirl[100][2000] = {0};
int colAvail[100][2000] = {0};

//@desc: pre process to get sumVal[i][j], sumBoy[i][j], sumGirl[i][j] and colAvail[i][j]
//@param n: indicate number of rows
//@param m: indicate number of cols
void preProcess(int n, int m) {
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			int leftVal, upVal, leftUpVal;
			int leftBoy, upBoy, leftUpBoy;
			int leftGirl, upGirl, leftUpGirl;
			int upColAvail;

			upVal = i > 0 ? sumVal[i-1][j] : 0;
			upBoy = i > 0 ? sumBoy[i-1][j] : 0;
			upGirl = i > 0 ? sumGirl[i-1][j] : 0;
			upColAvail = i > 0 ? colAvail[i-1][j] : 0;

			leftVal = j > 0 ? sumVal[i][j-1] : 0;
			leftBoy = j > 0 ? sumBoy[i][j-1] : 0;
			leftGirl = j > 0 ? sumGirl[i][j-1] : 0;

			leftUpVal = i > 0 && j > 0 ? sumVal[i-1][j-1] : 0;
			leftUpBoy = i > 0 && j > 0 ? sumBoy[i-1][j-1] : 0;
			leftUpGirl = i > 0 && j > 0 ? sumGirl[i-1][j-1] : 0;

			sumVal[i][j] = leftVal + upVal - leftUpVal + choirVal[i][j];
			sumBoy[i][j] = leftBoy + upBoy - leftUpBoy + (sexVal[i][j] == 1 ? 1 : 0);
			sumGirl[i][j] = leftGirl + upGirl - leftUpGirl + (sexVal[i][j] == 2 ? 1 : 0);
			colAvail[i][j] = choirVal[i][j] < 0 ? 0 : 1 + colAvail[i-1][j];
		}
	}
}

//@desc: update the max available choir value
void updateRes(int i, int ii, int j, int jj, int b, int g, int & res) {
	int leftVal, upVal, leftUpVal;
	int leftBoy, upBoy, leftUpBoy;
	int leftGirl, upGirl, leftUpGirl;
	int tempSum, tempBoy, tempGirl;

	upVal = i > 0 ? sumVal[i-1][jj] : 0;
	upBoy = i > 0 ? sumBoy[i-1][jj] : 0;
	upGirl = i > 0 ? sumGirl[i-1][jj] : 0;

	leftVal = j > 0 ? sumVal[ii][j-1] : 0;
	leftBoy = j > 0 ? sumBoy[ii][j-1] : 0;
	leftGirl = j > 0 ? sumGirl[ii][j-1] : 0;

	leftUpVal = i > 0 && j > 0 ? sumVal[i-1][j-1] : 0;
	leftUpBoy = i > 0 && j > 0 ? sumBoy[i-1][j-1] : 0;
	leftUpGirl = i > 0 && j > 0 ? sumGirl[i-1][j-1] : 0;

	tempSum = sumVal[ii][jj] + leftUpVal - leftVal - upVal;
	tempBoy = sumBoy[ii][jj] + leftUpBoy - leftBoy - upBoy;
	tempGirl = sumGirl[ii][jj] + leftUpGirl - leftGirl - upGirl;

	if (tempBoy < b || tempGirl < g) {
		return;
	}

	if (tempSum > res) {
		res = tempSum;
	}
}

int choirChoose(int n, int m, int b, int g){
	int res = -1;
	int i, ii, j, jj;
	int x, y;

	for (y = 0; y < n; y++) {
		stack<int> s;
		for (x = 0; x < m; x++) {
			while (!s.empty()) {
				int top = s.top();
				if (colAvail[y][x] < colAvail[y][top]) {
					s.pop();
					i = y - colAvail[y][top] + 1;
					ii = y;
					j = s.empty() ? 0 : s.top() + 1; 
					jj = x - 1;
					updateRes(i, ii, j, jj, b, g, res);
				} else {
					break;
				}
			}
			s.push(x);
		}		

		while (!s.empty()) {
			int top = s.top();
			s.pop();
			if (colAvail[y][top] == 0) {
				break;
			} else {
				i = y - colAvail[y][top] + 1;
				ii = y;
				j = s.empty() ? 0 : s.top() + 1;
				jj = m-1;
				updateRes(i, ii, j, jj, b, g, res);
			}
		}
	}

	return res;
}

int main()
{
	int n, m, b, g;
	while(cin>>n>>m>>b>>g){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin>>choirVal[i][j];
				cin>>sexVal[i][j];
			}
		}

		preProcess(n, m);
		int res = choirChoose(n, m, b, g);
		if(res < 0)
			cout<<"No solution!"<<endl;
		else
			cout<<res<<endl;
	}
}