/**************************************
Evaluate Reverse Polish Notation : https://leetcode.com/problems/evaluate-reverse-polish-notation/

Evaluate the value of an arithmetic expression in Reverse Polish Notation. 
Valid operators are +, -, *, /. Each operand may be an integer or another expression. 
Some examples:

["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
**/

//@time complexity: O(n)
//@space complexity: O(n)
int evalRPN(vector<string>& tokens) {
	stack<int> s;
	for (int i = 0; i < tokens.size(); i++) {
		if (isOperator(tokens[i])) {
			int num2 = s.top();
			s.pop();
			int num1 = s.top();
			s.pop();
			s.push(cal(num1, num2, tokens[i][0]));
		} else {
			s.push(strToInt(tokens[i]));
		}
	}

	return s.top();
}

int strToInt(string s) {
	if (s.size() <= 0) {
		return 0;
	}
	stringstream ss;
	int num;
	ss << s;
	ss >> num;
	return num;
}

bool isOperator(string s) {
	if (s.size() == 1 && (s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/')) {
		return true; 
	}
	return false;
}

int cal(int num1, int num2, char op) {
	if (op == '+') {
		return num1 + num2;
	}

	if (op == '-') {
		return num1 - num2;
	}

	if (op == '*') {
		return num1 * num2;
	}

	if (op == '/') {
		return num1/num2;
	}
}