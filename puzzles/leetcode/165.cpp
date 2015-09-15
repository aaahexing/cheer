/*************************************
Compare Version Numbers : https://leetcode.com/problems/compare-version-numbers/

Compare two version numbers version1 and version2.
 If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
 The . character does not represent a decimal point and is used to separate number sequences.
 For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:
0.1 < 1.1 < 1.2 < 13.37
**/

int compareVersion(string version1, string version2) {
	long long mainVersion1, mainVersion2;
	string minorVersion1, minorVersion2;
	int dotPos1, dotPos2;

	dotPos1 = version1.find('.');
	dotPos2 = version2.find('.');

	if (dotPos1 != -1) {
		mainVersion1 = strToLong(version1.substr(0, dotPos1));
		minorVersion1 = version1.substr(dotPos1 + 1);
	} else {
		mainVersion1 = strToLong(version1);
	}

	if (dotPos2 != -1) {
		mainVersion2 = strToLong(version2.substr(0, dotPos2));
		minorVersion2 = version2.substr(dotPos2 + 1);
	} else {
		mainVersion2 = strToLong(version2);
	}

	if (mainVersion1 > mainVersion2) {
		return 1;
	} else if (mainVersion1 < mainVersion2) {
		return -1;
	} else if (minorVersion1 == "" && minorVersion2 == "") {
		return 0;
	} else {
		return compareVersion(minorVersion1, minorVersion2);
	}
}

long long strToLong(string s) {
	if (s == "") {
		return 0;
	}
	long long n;
	stringstream ss;
	ss << s;
	ss >> n;
	return n;
}