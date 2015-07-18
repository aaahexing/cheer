#include <iostream>
using namespace std;

struct skewNode{
	int val;
	skewNode * left;
	skewNode * right;

	skewNode(int v, leftistNode * l = NULL, leftistNode * r = NULL): val(v), left(l), right(r){
	}
};

class skewHeap{
	skewHeap(skewHeap & rhs){
		root = clone(rhs.root);
	}

	leftistHeap(skewHeap * rhs){
		root = clone(rhs->root);
	}

	skewHeap(){
		root = NULL;
	}

	~skewHeap(){
		makeEmpty(root);
	}

	bool isEmpty(){
		return root == NULL;
	}

	void merge(skewHeap & rhs){
		if(this == & rhs)                       //don't forget this!!!!! IMPORTANT
			return ;     

		root = merge(root, rhs.root);
		rhs.root = NULL;
	}

	void insert(int val){
		root = merge(root, new skewNode(val));
	}

	void deleteMin(int & min){
		if(isEmpty())
			return;            //don't forget to check whether the heap is empty first!!!

		min = root->val;
		skewNode * old = root;
		root = merge(root->left, root->right);
		delete old;
	}

	void deleteMin(){
		if(isEmpty())
			return;

		skewNode * old = root;
		root = merge(root->left, root->right);
		delete old;
	}

private:
	skewNode * root;
	
	skewNode * clone(skewNode * r){
		if(r == NULL)
			return NULL;
		return new skewNode(r->val, clone(r->left), clone(r->right));
	}

	skewNode * merge(skewNode * h1, skewNode * h2){
		if(h1 == NULL)
			return h2;
		if(h2 == NULL)
			return h1;

		if(h1->val <= h2->val){
			h1->right = merge(h1->right, h2);
			swapChild(h1);
			return h1;
		}
		else
		{
			h2->right = merge(h1, h2->right);
			swapChild(h2);
			return h2;
		}
	}

	void swapChild(skewNode * h){
		skewNode * temp = h->left;
		h->left = h->right;
		h->right = temp;
	}

	void makeEmpty(leftistNode * r){
		if(root == NULL)
			return;

		makeEmpty(root->left);
		makeEmpty(root->right);
		delete r;

		r = NULL;
	}
};