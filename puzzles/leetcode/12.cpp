/****************************
Integer to Roman : https://leetcode.com/problems/integer-to-roman/

Given an integer, convert it to a roman numeral. 
Input is guaranteed to be within the range from 1 to 3999.
**/

//@1A
class Solution {
public:
    string intToRoman(int num) {
        int qian = num / 1000;
        int bai = (num - qian * 1000) / 100;
        int shi = (num - qian * 1000 - bai * 100) / 10;
        int ge = num - qian * 1000 - bai * 100 - shi * 10;
        
        string ret;
        char up, five, one;
        while (qian) {
            ret += 'M';
            qian--;
        }
        if (bai > 0) {
            ret += getRoman(bai, 'M', 'D', 'C');
        }
        if (shi > 0) {
            ret += getRoman(shi, 'C', 'L', 'X');
        }
        if (ge > 0) {
            ret += getRoman(ge, 'X', 'V', 'I');
        }
        return ret;
    }
    
    string getRoman(int num, char up, char five, char one) {
        string ret;
        if (num == 9) {
            ret += one;
            ret += up;
            num -= 9;
        }
        if (num == 4) {
            ret += one;
            num++;
        }
        if (num >= 5) {
            ret += five;
            num -= 5;
        }
        while (num) {
            ret += one;
            num--;
        }
        
        return ret;
    }
};