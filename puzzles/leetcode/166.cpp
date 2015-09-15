/************************
Fraction to Recurring Decimal: https://leetcode.com/problems/fraction-to-recurring-decimal/

Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.
For example,
Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
**/

//@desc: simulate the devision operation
//@desc: be specially careful of the boundry conditions such as the minimum positive int, positive denominator, etc...
string fractionToDecimal(int numerator, int denominator) {
    string ret;
    stringstream ss;
    unordered_map<int, int> m;
        
    if (denominator == 0) {
        return ret;
    }
        
    long long Numerator = numerator;
    long long Denominator = denominator;
        
    if (Denominator < 0) {
        Denominator = -Denominator;
        Numerator = -Numerator;
    }
        
    if (Numerator < 0) {
        ss << '-';
        Numerator = -Numerator;
    }
    ss << Numerator / Denominator;
        
    if (Numerator % Denominator == 0) {
        ss >> ret;
        return ret;
    }
    ss <<'.';
    ss >> ret;
        
    long long remain = Numerator % Denominator;
    int pos = 0;
    string s;
    while (remain) {
        if (m.find(remain) != m.end()) {
            s.insert(m[remain], 1, '(');
            s.insert(s.size(), 1, ')');
            break;
        }
            
        m[remain] = pos;
        s += intToStr((remain * 10) / Denominator);
        remain = (remain * 10) % Denominator;
        pos++;
    }
        
    ret += s;
    return ret;
}
    
string intToStr(long long n) {
    stringstream ss;
    string s;
    ss << n;
    ss >> s;
    return s;
}
