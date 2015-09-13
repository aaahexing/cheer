/************************************
Largest Number : https://leetcode.com/problems/largest-number/

Given a list of non negative integers, arrange them such that they form the largest number.
For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
Note: The result may be very large, so you need to return a string instead of an integer.
**/

//---------------------------first solution--------------------------------------------
//time complexity: O(nlogn)
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
            if (highestA < highestB) {
                return true;
            }
            if (highestA > highestB) {
                return false;
            }
            
            if (a / 10 == 0) {
                return a < getHighestNum(b/10);
            } 
            if (b / 10 == 0) {
                return b < getHighestNum(a/10);
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
        priority_queue<int, vector<int>, compare> heap(nums.begin(), nums.end());
        while (!heap.empty()) {
            int top = heap.top();
            heap.pop();
            stringstream s;
            string tmp;
            s << top;
            s >> tmp;
            ret += tmp;
        }
        return ret;
    }
};