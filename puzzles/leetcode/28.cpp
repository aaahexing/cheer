/********************************
Implement strStr() : https://leetcode.com/problems/implement-strstr/

Implement strStr(). 
Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack. 
**/

//@space complexity: O(m)
//@time complexity: O(m * n)    
//@1A
//@desc: time complexity can be optimized by KMP algorithm, however, I still can't imply this algorithm, and will come back later....
int strStr(string haystack, string needle) {
	int len = needle.size();
	for (int i = 0; i + len <= haystack.size(); i++) {
		string substack = haystack.substr(i, len);
		if (substack == needle) {
			return i;
		}
	}

	return -1;
}