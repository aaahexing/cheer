/*********************************
Roman to Integer: https://leetcode.com/problems/roman-to-integer/

Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.
**/

//@time complexity: O(n)
//@space complexity: O(1)
int romanToInt(string s) {
	int res = 0;
	map<char, int> m;
	m['I'] = 1;
	m['V'] = 5;
	m['X'] = 10;
	m['L'] = 50;
	m['C'] = 100;
	m['D'] = 500;
	m['M'] = 1000;
	for (int i = 0; i < s.size() -1 ; i++) {
		if (m[s[i]] < m[s[i+1]]) {
			res -= m[s[i]];
		} else {
			res += m[s[i]];
		}
	}
	if (s.size() > 0) {
		res += m[s[s.size() - 1]];
	}

	return res;
}