/************************************
Add Binary : https://leetcode.com/problems/add-binary/

Given two binary strings, return their sum (also a binary string). 
For example,
a = "11"
b = "1"
Return "100". 
**/

//@time complexity: O(max(m, n)), m, n represent the length of a and b
//@space complexity: O(1)
//@1A
string addBinary(string a, string b) {
	string ret;
	int lenA = a.size();
	int lenB = b.size();
	char JinWei = '0';
	int i, j;

	for (i = lenA - 1, j = lenB - 1; i >= 0 && j >= 0; i--, j--) {
		int sum = (a[i] - '0') + (b[j] - '0') + (JinWei - '0');
		int jin = sum / 2;
		int add = sum % 2;
		JinWei = jin + '0';
		ret = char(add + '0') + ret;
	}

	if (i < 0) {
		for (; j >= 0; j--) {
			int sum = (b[j] - '0') + (JinWei - '0');
			int jin = sum / 2;
			int add = sum % 2;
			JinWei = jin + '0';
			ret = char(add + '0') + ret;
		}
	} else {
		for (; i >= 0; i--) {
			int sum = (a[i] - '0') + (JinWei - '0');
			int jin = sum / 2;
			int add = sum % 2;
			JinWei = jin + '0';
			ret = char(add + '0') + ret;
		}
	}

	if (JinWei == '1') {
		ret = JinWei + ret;
	}

	return ret;
}