//ZOJ Problem Set - 1958 Friends
//http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemId=958
//time consumption: 3h ====crying..........
//Accepted by trying two time

#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

//add operation
//time complexity: max(O(m+n), MAX(O(mlogm), O(nlogn))
//m, n are the length of the input string s1 and s2, respectively
string add(string s1, string s2)
{
	string res;
	res.clear();
	int idx1=1, idx2=1;

	sort(s1.begin()+1, s1.end()-1);
	sort(s2.begin()+1, s2.end()-1);

	while(idx1 < s1.size()-1 && idx2 < s2.size()-1)
	{	
		if(s1[idx1] < s2[idx2])
			res += s1[idx1++];
		else if(s1[idx1] > s2[idx2])
			res += s2[idx2++];
		else
		{
			res += s1[idx1++];
			idx2++;
		}
	}

	if(idx1 == s1.size()-1)
		res += s2.substr(idx2, s2.size()-1-idx2);
	else if(idx2 == s2.size()-1)
		res += s1.substr(idx1, s1.size()-1-idx1);
	else
		;          //wouldn't occur
	res.insert(res.begin(), '{');
	res.insert(res.end(), '}');
	return res;
}

//sub operation
//time complexity: max(O(m+n), MAX(O(mlogm), O(nlogn))
//m, n are the length of the input string s1 and s2, respectively
string sub(string s1, string s2)
{
	string res;
	res.clear();
	int idx1 = 1, idx2 = 1;

	sort(s1.begin()+1, s1.end()-1);
	sort(s2.begin()+1, s2.end()-1);

	while(idx1 < s1.size()-1 && idx2 < s2.size()-1)
	{
		if(s1[idx1] < s2[idx2])
			res += s1[idx1++];
		else if(s1[idx1] > s2[idx2])
			idx2++;
		else
		{
			idx1++;
			idx2++;
		}
	}
	if(idx1 < s1.size()-1)
		res += s1.substr(idx1, s1.size()-1-idx1);

	res.insert(res.begin(), '{');
	res.insert(res.end(),'}');
	return res;
}

//mul operation
//time complexity: max(O(m+n), MAX(O(mlogm), O(nlogn))
//m, n are the length of the input string s1 and s2, respectively
string mul(string s1, string s2)
{
	string res;
	res.clear();
	int idx1=1, idx2=1;

	sort(s1.begin()+1, s1.end()-1);
	sort(s2.begin()+1, s2.end()-1);

	while(idx1 < s1.size()-1 && idx2 < s2.size()-1)
	{
		if(s1[idx1] < s2[idx2])
			idx1++;
		else if(s1[idx1] > s2[idx2])
			idx2++;
		else
		{
			res += s1[idx1];
			idx1++;idx2++;
		}
	}

	res.insert(res.begin(), '{');
	res.insert(res.end(),'}');
	return res;
}

//return the priority of the operator
//time complexity: O(1)
int priority(char c)
{
	if(c == '+' || c == '-')
		return 1;
	else if(c == '*')
		return 2;
	else if(c == '(')
		return 3;
	else
		return 0;
}

//To do the corresponding operation according to the input parameter
//Time complexity: max(O(m+n), MAX(O(mlogm), O(nlogn))
////m, n are the length of the input string s1 and s2, respectively
string operation(const string s1, const string s2, char op)
{
	if(op == '+')
		return add(s1, s2);
	else if(op == '-')
		return sub(s1, s2);
	else if(op == '*')
		return mul(s1, s2);
	else
		;
}

//the main function to do a calculation
//time complexity: O(nlogn)?? I guess
//n represents the length of input string s
string calculate(const string s)
{
	string res;
	res.clear();

	if(s.size() == 0)
		return res;
	
	stack<string> operant;
	stack<char> op;
	int start = 0, end = 0;

	while(end < s.size())
	{
		if(s[end] == '+' || s[end] == '-' || s[end] == '*' || s[end] == '(' || s[end] == ')')
		{
			if(end - start > 0)
			{
				string sTmp= s.substr(start, end-start);
				operant.push(sTmp);
			}

			if(s[end] == '+' || s[end] == '-' || s[end] == '*' || s[end] == '(')
			{
				while(!op.empty())
				{
					char tmp = op.top();
					if(tmp == '(')
						break;
					if(priority(tmp) >= priority(s[end]))
					{
						string s2 = operant.top();
						operant.pop();
						string s1 = operant.top();
						operant.pop();
						operant.push(operation(s1, s2, tmp));
						op.pop();
					}
					else
						break;
				}
			
				op.push(s[end]);
			}
			else
			{
				while(!op.empty())
				{
					char tmp = op.top();
					op.pop();

					if(tmp == '(')	
						break;

					string s2 = operant.top();
					operant.pop();
					string s1 = operant.top();
					operant.pop();
					operant.push(operation(s1, s2, tmp));
				}
			}

			start = end = end + 1;
		}
		else 
			end++;
	}

	if(end - start > 0)
	{
		string sTmp= s.substr(start, end-start);
		operant.push(sTmp);
	}

	while(!op.empty())
	{
		char tmp = op.top();
		op.pop();
		string s2 = operant.top();
		operant.pop();
		string s1 = operant.top();
		operant.pop();
		operant.push(operation(s1, s2, tmp));
	}

	return operant.top();
}

//main function
//the access of the program
int main(int argc, char ** argv)
{
	string s;
	while(getline(cin, s))
	{
		cout<<calculate(s)<<endl;
	}
	return 0;
}