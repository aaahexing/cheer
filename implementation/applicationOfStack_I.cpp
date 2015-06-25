#include <iostream>
#include <stack>
using namespace std;

//check the string is balanced.
//return true if it is
//time complexity: O(n)
//space complexity: O(n)
//Note: for simplicity, we only check for balancing of parentheses, brackets, and braces and ignore any other character that appears.
bool balanceSymbol(string s)
{
  if(s.size() == 0)
    return true;
  stack<char> sta;
  sta.clear();
  
  for(int i=0; i<s.size(); i++)
  {
    if(s[i] == '(' || s[i] == '[' || s[i] == '{')
      sta.push(s[i]);
    
    if(s[i] == ')' || s[i] == ']' || s[i] == '}')
    {
      if(s.empty())
      {
        sta.clear();
        return false;
      }
      else
      {
        if((s[i] == ')' && s.top() != '(') || (s[i] == ']' && s.top() != '[') || (s[i] == '}' && s.top() != '{'))
          sta.clear();
          return false;
        else
          sta.pop();
      }
    }
  }
  
  if(sta.empty())            // don't forget the last check... 
    return true;
  else
    return false;
}

