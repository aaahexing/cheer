#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//time compelxity: O(m^2*n^2)
//space complexity: O(m*n)
//Time limit exceeded
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

			if(i > 0){
				leftVal = sumVal[i-1][j];
				leftBoy = sumBoy[i-1][j];
				leftGirl = sumGirl[i-1][j];
				leftNotAvail = notAvail[i-1][j];
			}else{
				leftVal = 0;
				leftBoy = 0;
				leftGirl = 0;
				leftNotAvail = 0;
			}

			if(j > 0){
				upVal = sumVal[i][j-1];
				upBoy = sumBoy[i][j-1];
				upGirl = sumGirl[i][j-1];
				upNotAvail = notAvail[i][j-1];
			}else{
				upVal = 0;
				upBoy = 0;
				upGirl = 0;
				upNotAvail = 0;
			}

			if(i > 0 && j > 0){
				leftUpVal = sumVal[i-1][j-1];
				leftUpBoy = sumBoy[i-1][j-1];
				leftUpGirl = sumGirl[i-1][j-1];
				leftUpNotAvail = notAvail[i-1][j-1];
			}else{
				leftUpVal = 0;
				leftUpBoy = 0;
				leftUpGirl = 0;
				leftUpNotAvail = 0;
			}

			sumVal[i][j] = leftVal + upVal - leftUpVal + choirVal[i][j];
			sumBoy[i][j] = leftBoy + upBoy - leftUpBoy + (sexVal[i][j] == 1 ? 1 : 0);
			sumGirl[i][j] = leftGirl + upGirl - leftUpGirl + (sexVal[i][j] == 2 ? 1 : 0);
			notAvail[i][j] = leftNotAvail + upNotAvail - leftUpNotAvail + (choirVal[i][j] < 0 ? 1 : 0);
		}
	}

	int res = -1;
	int tempSum, tempBoy, tempGirl, tempNotAvail;

	for(int i = 0; i < n; i++){
		for(int ii = i; ii < n; ii++){
			for(int j = 0; j < m; j++){
				for(int jj = j; jj < m; jj++){
					int leftVal, upVal, leftUpVal;
					int leftBoy, upBoy, leftUpBoy;
					int leftGirl, upGirl, leftUpGirl;
					int leftNotAvail, upNotAvail, leftUpNotAvail;

					if(i > 0){
						leftVal = sumVal[i-1][j];
						leftBoy = sumBoy[i-1][j];
						leftGirl = sumGirl[i-1][j];
						leftNotAvail = notAvail[i-1][j];
					}else{
						leftVal = 0;
						leftBoy = 0;
						leftGirl = 0;
						leftNotAvail = 0;
					}

					if(j > 0){
						upVal = sumVal[i][j-1];
						upBoy = sumBoy[i][j-1];
						upGirl = sumGirl[i][j-1];
						upNotAvail = notAvail[i][j-1];
					}else{
						upVal = 0;
						upBoy = 0;
						upGirl = 0;
						upNotAvail = 0;
					}

					if(i > 0 && j > 0){
						leftUpVal = sumVal[i-1][j-1];
						leftUpBoy = sumBoy[i-1][j-1];
						leftUpGirl = sumGirl[i-1][j-1];
						leftUpNotAvail = notAvail[i-1][j-1];
					}else{
						leftUpVal = 0;
						leftUpBoy = 0;
						leftUpGirl = 0;
						leftUpNotAvail = 0;
					}

					tempSum = sumVal[ii][jj] + leftUpVal - leftVal - upVal;
					tempBoy = sumBoy[ii][jj] + leftUpBoy - leftBoy - upBoy;
					tempGirl = sumGirl[ii][jj] + leftUpGirl - leftGirl - upGirl;
					tempNotAvail = notAvail[ii][jj] + leftUpNotAvail - leftNotAvail - upNotAvail;

					if(tempBoy < b || tempGirl < g){
						continue;
					}

					if(tempNotAvail > 0)
						continue;

					if(tempSum > res)
						res = tempSum;
				}
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