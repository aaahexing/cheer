#include <iostream>
#include <stack>
using namespace std;

bool isDigit(char c)
{
  return c >= '0' && c <= '9';
}

//return the priority of the input parameter
//if the input character is an error symbol, return -1
int priority(char c)
{
  if(c == '+' || c == '-')
    return 1;
  else if(c == '*' || c == '/')
    return 2;
  else if(c == '(')
    return 3;
    
  return -1;
}

//convert a infix expression to a postfix one
//input: the infix expression
//output: the postfix expression
//Note: the infix expression is right and the scope of digit is '0' to '9' and only '(', ')', '+', '-', '*', '/' symbols are legal.
string infixToPostfixConversion(string s)
{
  string res;
  res.clear();
  
  stack<char> sta;
  sta.clear();
  
  for(int i=0; i<s.size(); i++)
  {
    if(isDigit(s[i]))
      s.push_back(s[i]);
    else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '(')
    {
      while(!sta.empty())
      {
        char temp = sta.top();
        if(temp == '(')
          break;
        if(priority(temp) >= priority(s[i]))
        {
          s.push_back(temp);
          sta.pop();
        }
		else
			break;
      }
      sta.push(s[i]);
    }
    else if(s[i] == ')')
    {
      while(!sta.empty())
      {
        char temp = sta.top();
        sta.pop();
        if(temp == '(')
          break;
        res.push_back(temp);
      }
    }
    else
      throw symbolOutOfBandException{};
  }
  
  while(!sta.empty())
  {
    res.push_back(sta.top())
    sta.pop();
  }
  return res;
}
