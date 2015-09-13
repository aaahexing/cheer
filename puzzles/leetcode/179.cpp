/************************************
Largest Number : https://leetcode.com/problems/largest-number/

Given a list of non negative integers, arrange them such that they form the largest number.
For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
Note: The result may be very large, so you need to return a string instead of an integer.
**/

//---------------------------first solution--------------------------------------------
//time complexity: O(nlogn * maxlength(input[i]))
//space complexity: O(n)
//time limit exceeded
class compare {
public:
	bool operator() (int a, int b) {
		int digitA, highestA;
		int digitB, highestB;
		digitA = getDigit(a);
		digitB = getDigit(b);

		while (true) {
			highestA = getHighestNum(a);
			highestB = getHighestNum(b);
			if (highestA > highestB) {
				return true;
			}
			if (highestA < highestB) {
				return false;
			}

			if (a / 10 == 0 && b / 10 == 0) {
				return a > b;
			}
			if (a / 10 == 0) {
				b = b - highestB * pow(10.0, digitB - 1);
				return a >= getHighestNum(b);
			} 
			if (b / 10 == 0) {
				a = a - highestA * pow(10.0, digitA - 1);
				return getHighestNum(a) > b;
			}
			a = a - highestA * pow(10.0, --digitA);
			b = b - highestB * pow(10.0, --digitB);
		}
	}

	int getHighestNum(int n) {
		while (n / 10) {
			n /= 10;
		}
		return n;
	}

	int getDigit(int n) {
		int digit = 0;
		while (n) {
			digit++;
			n /= 10;
		}
		return digit;
	}
};

class Solution {
public:
	string largestNumber(vector<int>& nums) {
		string ret;
		compare cmp;
		sort(nums.begin(), nums.end(), cmp);
		for (int i = 0; i < nums.size(); i++) {
			string tmp;
			stringstream ss;
			ss << nums[i];
			ss >> tmp;
			ret = ret + tmp;
		}
		return ret;
	}
};

//----------------------------------------second solution-----------------------------------
//time complexity: O(nlogn)
//space complexity: O(1)
//@note: be specailly careful of the compare class...
class compare {
public:
	bool operator() (int a, int b) {
		string ab;
		string ba;
		ab = intToStr(a) + intToStr(b);
		ba = intToStr(b) + intToStr(a);
		return ab > ba;
	}

	string intToStr(const int a) {
		stringstream ss;
		string tmp;
		ss << a;
		ss >> tmp;
		return tmp;
	}
};

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ret;
		compare cmp;
		sort(nums.begin(), nums.end(), cmp);
		for (int i = 0; i < nums.size(); i++) {
			string tmp;
			stringstream ss;
			ss << nums[i];
			ss >> tmp;
			if (tmp == "0" && i == 0) {
			    return tmp;
			}
			ret = ret + tmp;
		}
        return ret;
    }
};