#include <iostream>
#include <algorithm>
using namespace std;

struct SplayNode{
	int element;
	SplayNode * left;
	SplayNode * right;
	SplayNode(int e, SplayNode * l = NULL, SplayNode * r = NULL):element(e), left(l), right(r){
	}
};

class SplayTree
{
private:
	SplayNode * root;
public:
	SplayTree(SplayNode * r = NULL): root(r)
	{}

	~SplayTre(){
		clear(root);
	}

	SplayNode * findMin() const
	{
		return findMin(root);
	}

	SplayNode * findMax() const
	{
		return findMax(root);
	}

	void insert(int x)
	{
		root = insert(root, x);
		root = splay(root, x);
	}

	SplayNode * find(int x)
	{
		if(find(root, x) == NULL)
			return NULL;
		root = splay(root, x);
		return root;
	}

	void remove(int x)
	{
		root = remove(root, x);
	}

private:
	clear(SplayNode * root)
	{
		if(root == NULL)
			return;
		clear(root->left);
		clear(root->right);
		delete root;
		root = NULL;
	}

	SplayNode * findMin(SplayNode * root) const
	{
		if(root == NULL)
			return NULL;
		return root->left == NULL ? root : findMin(root->left);
	}

	SplayNode * findMax(SplayNode * root) const
	{
		if(root == NULL)
			return NULL;
		return root->right == NULL ? root : findMax(root->right);
	}

	SplayNode * insert(SplayNode * root, int x)
	{
		if(root == NULL)
			return new SplayNode(x, NULL, NULL);
		else
		{
			if(x < root->element)
				root->left = insert(root->left, x);
			else if(x > root->element)
				root->right = insert(root->right, x);
			else
				;
		}

		return root;
	}

	SplayNode * remove(SplayNode * root, int x)
	{
		if(root == NULL)
			return NULL;
		else
		{
			if(x < root->element)
				root->left = remove(root->left, x);
			else if(x > root->element)
				root->right = remove(root->right, x);
			else
			{
				if(root->left && root->right)
				{
					root->element = findMax(root->left)->element;
					root->left = remove(root->left, root->element);
				}
				else
				{
					SplayNode * temp = root;
					root = root->left ? root->left : root->right;
					delete temp;
				}
			}
		}

		return root;
	}

	SplayNode * find(SplayNode * root, int x) const
	{
		if(root == NULL)
			return NULL;
		else
		{
			if(x < root->element)
				return find(root->left, x);
			else if(x > root->element)
				return find(root->right, x);
			else
				return root;
		}
	}

	//The precondition is x in the tree root...
	SplayNode * splay(SplayNode * root, int x)
	{
		while(root->element != x)
		{

		}
	}
}

