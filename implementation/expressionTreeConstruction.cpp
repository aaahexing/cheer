#include <algorithm>
#include <stack>
#include <string>
using namespace std;

struct Node
{
  char element;
  Node * left;
  Node * right;
  
  struct Node(char e, Node * l = nullptr, Node * r = nullptr): element = e, left = l, right = r
  {}
};

enum Classification{
  OPERATOR,
  OPERANT,
  UNKOWN
};

Classification symRecog(char c)
{
  if(c >= '0' && c <= '9')
    return OPERANT;
  else if(c == '+' || c == '-' || c == '*' || c == '/')
    return OPERATOR;
  else
    return UNKOWN;
}

//input: the postfix expression tree
//output: pointer to the new tree
//Node: the input postfix tree is correct to simplify this program; the operand is from '0' to '9'; only support operator '+', '-', '*', '/'
Node * expressionTreeConstruction(string s)
{
  if(s.empty())
    return nullptr;
    
  stack<Node *> sta;
  sta.clear();
  
  for(int i=0; i<s.size(); i++)
  {
    if(symRecg(s[i]) == OPERANT)
    {
      Node * temp = new Node(s[i]);
      sta.push(temp);
    }
    else if(symRecg(s[i]) == OPERATOR)
    {
      Node * left = sta.top();
      sta.pop();
      Node * right = sta.top();
      sta.pop();
      Node * temp = new Node(s[i], left, right);
      sta.push(temp);
    }
    else
      throw symbolOutOfException{};
  }
  
  if(sta.size() == 1)
  {
    Node * res = sta.top();
    sta.clear();
    return res;
  }
  else
    throw expressionOutOfException{};
}
