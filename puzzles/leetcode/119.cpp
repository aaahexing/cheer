/******************************
Pascal's Triangle II : https://leetcode.com/problems/pascals-triangle-ii/

Given an index k, return the kth row of the Pascal's triangle.
For example, given k = 3,
Return [1,3,3,1]. 
Note:
Could you optimize your algorithm to use only O(k) extra space? 
**/

//@time complexity: O(row^2)
//@space complexity: O(row)
//@2A
vector<int> getRow(int rowIndex) {
	vector<int> kRow(rowIndex + 1);
	vector<int> lastRow(rowIndex);
	for (int i = 0; i <= rowIndex; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				kRow[j] = 1;
			} else {
				kRow[j] = lastRow[j - 1] + lastRow[j];
			}
		}

		if (i != rowIndex) {
			for (int j = 0; j <= i; j++) {
				lastRow[j] = kRow[j];
			}
		}
	}

	return kRow;
}