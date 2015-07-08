#include <algorithm>
#include <iostream>
using namespace std;

struct AVLNode
{
	int element;
	int height;
	AVLNode * left;
	AVLNode * right;

	AVLNode(int e, int h=0, AVLNode * l=NULL, AVLNode * r=NULL): element(e), height(h), left(l), right(r)
	{}
};

int getHeight(AVLNode * node)
{
	return node == NULL ? -1 : node->height;
}

class AVLTree
{
private:
	AVLNode * root;
	AVLTree(AVLNode * r = NULL): root(r)
	{}
	~AVLTree()
	{
		releaseSpace(root);
	}
	void releaseSpace(AVLNode * root)
	{
		if(root == NULL)
			return;
		releaseSpace(root->left);
		releaseSpace(root->right);
		delete root;
		root = NULL;
	}

public:
	AVLNode * findMin()
	{
		return findMin(root);
	}
	AVLNode * findMax()
	{
		return findMax(root);
	}
	void insert(int x)
	{
		insert(root, x);
	}
	void remove(int x)
	{
		remove(root, x);
	}

private:
	//time complexity:O(logn)
	AVLNode * findMin(AVLNode * root)
	{
		if(root == NULL)
			return NULL;
		else
			return root->left == NULL ? root : findMin(root->left);
	}

	//time complexity: O(logn)
	AVLNode * findMax(AVLNode * root)
	{
		if(root == NULL)
			return NULL;
		else
			return root->right == NULL ? root : findMax(root->right);
	}

	//time complexity: O(1)
	inline void updateHeight(AVLNode * root)
	{
		root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
	}

	//time complexity: O(logn), since AVL tree is a balance tree and time consumption is the height of the tree
	AVLNode * insert(AVLNode * root, int x)
	{
		if(root == NULL)
			return new AVLNode(x, 0, NULL, NULL);
		else
		{
			if(x < root->element)
				root->left = insert(root->left, x);
			else if(x > root->element)
				root->right = insert(root->right, x);
			else
				;          //do nothing, since x is in the AVL tree already...
		}

		root = balance(root);
		return root;
	}

	//time complexity: > O(logn)
	AVLNode * remove(AVLNode * root, int x)
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
					AVLNode * temp = root;
					root = root->left == NULL ? root->right : root->left;
					delete temp;
				}
			}
		}

		root = balance(root);
		return root;
	}
	
	//time complexity: O(1)
	AVLNode * balance(AVLNode * root)
	{
		if(root == NULL)
			return root;
		if(getHeight(root->left) - getHeight(root->right) > 1)              //Notice: can't write as root->left->height as root->left may be NULL, then, the height parameter doesn't exit and an error would occur...
		{
			if(getHeight(root->left->left) >= getHeight(root->left->right))      // when doing deleting operation, left->left->height may equal to left->right->height. So, we need an '=', here
				root = singleRotationL(root);
			else
				root = doubleRotationL(root);
		}
		else if(getHeight(root->right) - getHeight(root->left) > 1)
		{
			if(getHeight(root->right->left) <= getHeight(root->right->right))
				root = singleRotationR(root);
			else
				root = doubleRotationR(root);
		}

		updateHeight(root);
		return root;
	}

	//                     A                           B
	//                    / \                         / \
	//                   B   C         -->           D+  A
	//                  / \                             / \
	//                 D+  E                           E   C
	//time complexity: O(1)
	AVLNode * singleRotationL(AVLNode * root)
	{
		AVLNode * res = root->left;
		AVLNode * temp = root->left->right;
		root->left->right = root;
		root->left = temp;
		updateHeight(root);
		updateHeight(res);
		return res;
	}

	//                     A                           C 
	//                    / \                         / \
	//                   B   C         -->           A   E+
	//                      / \                     / \
	//                     D   E+                  B   D
	//time complexity: O(1)
	AVLNode * singleRotationR(AVLNode * root)
	{
		AVLNode * res = root->right;
		AVLNode * temp = root->right->left;
		root->right->left = root;
		root->right = temp;
		updateHeight(root);        // don't forget these two steps, since the branches are changed and the height information should be update also 
		updateHeight(res);           // update the subtree, then, update the parent
		return res;
	}

	//                    A                                
	//                   / \                               E
	//                  B   C                             / \
	//                 / \            -->                B   A
	//                D   E                             / \ / \
	//                   / \                           D  F G  C
	//                  F   G
	//time complexity: O(1)
	AVLNode * doubleRotationL(AVLNode * root)
	{
		root->left = singleRotationR(root->left);
		return singleRotationL(root);
	}

	//                    A
	//                   / \
	//                  B   C
	//                     / \
	//                    D   E
	//                   / \
	//                  F   G
	AVLNode * doubleRotationR(AVLNode * root)
	{
		root->right = singleRotationL(root->right);
		return singleRotationR(root);
	}
}