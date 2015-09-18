/***************************************
Excel Sheet Column Number : https://leetcode.com/problems/excel-sheet-column-number/

Related to question Excel Sheet Column Title
Given a column title as appear in an Excel sheet, return its corresponding column number.
For example:
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
**/

//@time complexity: O(n)
//@space complexity: O(1)
//@1A
int titleToNumber(string s) {
	if(s.size() <= 0) {
		return 0;
	}
	const int num = 26;
	int ret = 0;
	for(int i = 0; i < s.size(); i++) {
		ret = ret * num + (s[i] - 'A' + 1);
	}

	return ret;
}