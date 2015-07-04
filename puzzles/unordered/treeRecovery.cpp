//ZOJ Problem Set - 1944 TreeRecovery
//http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemId=944
//time consumption: 20min+10bug fix.....
//Accepted by trying two time (once: choosing C++, error run; the other: choosing C++0x, AC, nullptr is a new feature in C++0x, so, choose this one)

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

struct Node
{
	char element;
	Node * left;
	Node * right;
	Node(char e, Node * l, Node * r): element(e), left(l), right(r) 
	{}
};


//recover the tree by preorder and inorder string
//return the pointer to the root
//time complexity: O(n)
//n is the length of the input string
Node * TreeRecover(string preorder, string inorder)
{
	if(preorder.size() <= 0 || inorder.size() <= 0 || preorder.size() != inorder.size() )
		return nullptr;
	Node * n = new Node(preorder[0], nullptr, nullptr);
	int idx = inorder.find(preorder[0]);
	n->left = TreeRecover(preorder.substr(1, idx), inorder.substr(0,idx));
	n->right = TreeRecover(preorder.substr(idx+1, preorder.size()-1-idx), inorder.substr(idx+1, inorder.size()-1-idx));

	return n;
}

//postorder travel the binary tree
//return the postorder string
//time complexity: O(n)
string postorderTraversal(Node * root)
{
	string res;
	if(root == nullptr)
		return res;

	res += postorderTraversal(root->left);
	res += postorderTraversal(root->right);
	res += root->element;

	return res;
}

//release the space occupied by the tree
void deleteTree(Node * root)
{
	if(root == nullptr)
		return ;

	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
	root = nullptr;
}

int main(int argc, char ** argv)
{
	string preorder, inorder;
	while(cin>>preorder>>inorder)
	{
		Node * root = TreeRecover(preorder, inorder);
		string res = postorderTraversal(root);
		cout<<res<<endl;
		deleteTree(root);
	}
	return 0;
}