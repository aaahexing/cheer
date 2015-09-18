/***************************************
Excel Sheet Column Title : https://leetcode.com/problems/excel-sheet-column-title/

Given a positive integer, return its corresponding column title as appear in an Excel sheet.
For example:
1 -> A
2 -> B
3 -> C
...
26 -> Z
27 -> AA
28 -> AB 
**/

//@time complexity: O(log26 n)
//@space complexity: O(1)
//@1A
string convertToTitle(int n) {
	string ret;
	const int num = 26;
	if (n <= 0) {
		return ret;
	}

	while(n) {
		n = n - 1;
		ret.insert(ret.begin(), 'A' + (n % num));
		n /= num;
	}

	return ret;
}