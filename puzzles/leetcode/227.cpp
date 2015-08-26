/*******************
Basic Calculator II : https://leetcode.com/problems/basic-calculator-ii/

Implement a basic calculator to evaluate a simple expression string.
The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
You may assume that the given expression is always valid.
Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
**/

//time complexity: O(n)
//space complexity: O(n)
//1A, some bugs fixed
int calculate(string s) {
	int lastOpPos = -1;
	int pos;
	stack<char> op;
	stack<int> opr;

	for (pos = 0; pos < s.size(); pos++) {
		if (isOp(s[pos])) {
			string oprStr = s.substr(lastOpPos+1, pos - lastOpPos -1);
			opr.push(atoi(oprStr.c_str()));

			while ((!op.empty()) && (level(op.top()) >= level(s[pos]))) {
				int opr2 = opr.top();
				opr.pop();
				int opr1 = opr.top();
				opr.pop();

				char ope = op.top();
				op.pop();

				opr.push(cal(ope, opr1, opr2));
			}

			op.push(s[pos]);
			lastOpPos = pos;
		}
	}

	string oprStr = s.substr(lastOpPos+1, pos - lastOpPos -1);
	opr.push(atoi(oprStr.c_str()));

	while (!op.empty()) {
		char ope = op.top();
		op.pop();

		int opr2 = opr.top();
		opr.pop();
		int opr1 = opr.top();
		opr.pop();

		opr.push(cal(ope, opr1, opr2));
	}

	return opr.top();
}

bool isOp(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

int level(char c) {
	if (c == '+' || c == '-') {
		return 1;
	}

	if (c == '*' || c == '/') {
		return 2;
	}
}

int cal(char op, int opr1, int opr2) {
	if (op == '+') {
		return opr1 + opr2;
	}

	if (op == '-') {
		return opr1 - opr2;
	}

	if (op == '*') {
		return opr1 * opr2;
	}

	if (op == '/') {
		return opr1 / opr2;
	}
}