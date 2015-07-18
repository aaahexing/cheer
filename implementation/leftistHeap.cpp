#include <iostream>
using namespace std;

struct leftistNode{
	int val;
	leftistNode * left;
	leftistNode * right;
	int npl;

	leftistNode(int v, leftistNode * l = NULL, leftistNode * r = NULL, int l = 0): val(v), left(l), right(r), npl(l){
	}
};

class leftistHeap{
	leftistHeap(leftistHeap & rhs){
		root = clone(rhs.root);
	}

	leftistHeap(leftistHeap * rhs){
		root = clone(rhs->root);
	}

	leftistHeap(){
		root = NULL;
	}

	~leftistHeap(){
		makeEmpty(root);
	}

	bool isEmpty(){
		return root == NULL;
	}

	void merge(leftistHeap & rhs){
		if(this == & rhs)                       //don't forget this!!!!! IMPORTANT
			return ;     

		root = merge(root, rhs.root);
		rhs.root = NULL;
	}

	void insert(int val){
		root = merge(root, new leftistNode(val));
	}

	void deleteMin(int & min){
		if(isEmpty())
			return;            //don't forget to check whether the heap is empty first!!!

		min = root->val;
		leftistNode * old = root;
		root = merge(root->left, root->right);
		delete old;
	}

	void deleteMin(){
		if(isEmpty())
			return;

		leftistNode * old = root;
		root = merge(root->left, root->right);
		delete old;
	}

private:
	leftistNode * root;
	
	leftistNode * clone(leftistNode * r){
		if(r == NULL)
			return NULL;

		return new leftistNode(r->val, clone(r->left), clone(r->right), r->npl);
	}

	leftistNode * merge(leftistNode * h1, leftistNode * h2){
		if(h1 == NULL)
			return h2;
		if(h2 == NULL)
			return h1;

		if(h1->val <= h2->val){
			h1->right = merge(h1->right, h2);
			if(getNPL(h1->left) < getNPL(h1->right))
				swapChild(h1);
			updateNPL(h1);
			return h1;
		}
		else
		{
			h2->right = merge(h1, h2->right);
			if(getNPL(h2->left) < getNPL(h2->right))
				swapChild(h2);
			updateNPL(h2);
			return h2;
		}
	}

	int getNPL(leftistNode * h){
		return h == NULL ? -1 : h->npl;
	}

	void swapChild(leftistNode * h){
		leftistNode * temp = h->left;
		h->left = h->right;
		h->right = temp;
	}

	void updateNPL(leftistNode * h){
		h->npl = getNPL(h->right) + 1;
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