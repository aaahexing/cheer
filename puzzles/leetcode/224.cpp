/*****************************************
Basic Calculator: https://leetcode.com/problems/basic-calculator/

Implement a basic calculator to evaluate a simple expression string.
The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces 
You may assume that the given expression is always valid.
Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
**/

//time complexity: O(n)
//NA : havn't think it clearly before writing....
int calculate(string s) {
	stack<int> opr;
	stack<char> op;
	int lastOp = -1;
	int i;

	for (i = 0; i < s.size(); i++) {
		if (isOp(s[i])) {
			string oprT = s.substr(lastOp + 1, i - lastOp -1);
			if (checkAvail(oprT)) {
				opr.push(atoi(oprT.c_str()));
			}

			if (s[i] == '(') {
				op.push(s[i]);
			} else if (s[i] != ')') {
				while ((!op.empty()) && op.top() != '(' && level(op.top()) >= level(s[i])) {
					int opr2 = opr.top();
					opr.pop();
					int opr1 = opr.top();
					opr.pop();

					char opT = op.top();
					op.pop();

					opr.push(cal(opr1, opr2, opT));
				}
				op.push(s[i]);
			} else {
				while (op.top() != '(') {
					int opr2 = opr.top();
					opr.pop();
					int opr1 = opr.top();
					opr.pop();

					char opT = op.top();
					op.pop();

					opr.push(cal(opr1, opr2, opT));
				}
				op.pop();
			}

			lastOp = i;
		}
	}

	string oprT = s.substr(lastOp + 1, i - lastOp -1);
	if (checkAvail(oprT)) {
		opr.push(atoi(oprT.c_str()));
	}

	while (!op.empty()) {
		int opr2 = opr.top();
		opr.pop();
		int opr1 = opr.top();
		opr.pop();

		char opT = op.top();
		op.pop();

		opr.push(cal(opr1, opr2, opT));
	}

	return opr.top();
}


bool isOp(char c) {
	return c == '+' || c == '-' || c == '(' || c== ')';
}

bool checkAvail(string s) {
	for (int i = 0; i < s.size(); i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			return true;
		}
	}

	return false;
}

int level(char op) {
	if (op == '(') {
		return 1;
	}

	if (op == '+' || op == '-') {
		return 2;
	}

	if (op == ')') {
		return 3;
	}
}

int cal(int opr1, int opr2, char op) {
	if (op == '+') {
		return opr1 + opr2;
	}

	if (op == '-') {
		return opr1 - opr2;
	}
}