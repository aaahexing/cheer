#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//time compelxity: O(m*n^2)
//space complexity: O(m*n)
//Wrong answer
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

	for(int i = 0; i < n; i++){
		for(int ii = i; ii < n; ii++){
			int j = 0;
			for(int jj = j; jj < m; jj++){
				int leftVal, upVal, leftUpVal;
				int leftBoy, upBoy, leftUpBoy;
				int leftGirl, upGirl, leftUpGirl;
				int leftColNotAvail, upColNotAvail, leftUpColNotAvail;

				upVal = i > 0 ? sumVal[i-1][j] : 0;
				upBoy = i > 0 ? sumBoy[i-1][j] : 0;
				upGirl = i > 0 ? sumGirl[i-1][j] : 0;
				upColNotAvail = i > 0 ? notAvail[i-1][j] : 0;

				leftVal = j > 0 ? sumVal[i][j-1] : 0;
				leftBoy = j > 0 ? sumBoy[i][j-1] : 0;
				leftGirl = j > 0 ? sumGirl[i][j-1] : 0;
				leftColNotAvail = jj > 0 ? notAvail[i][jj-1] : 0;

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
					break;
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
