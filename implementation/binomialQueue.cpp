#include<iostream>
using namespace std;
template<typename objectType>

struct BinomialNode{
	objectType val;
	BinomialNode * leftChild;
	BinomialNode * nextSibling;

	BinomialNode(objectType v, BinomialNode * lC = NULL, BinomialNode * nS = NULL): val(v), leftChild(lC), nextSibling(nS) {
	}
}; 

class BinomialQueue{
public:
	BinomialQueue(){
		theTrees.clear();
		treeNum = 0;
	}

	BinomialQueue(objectType obj){
		BinomialNode * root = new BinomialNode(obj);
		treeNum = 1;
		if(treeNum >= theTrees.size())
			theTrees.resize(2 * theTrees.size() + 1);
		theTrees.clear();
		theTrees.push_back(root);
	}

	BinomialQueue(const BinomialQueue & BQ){
		if(theTrees.size() < BQ.capacity())       //Is the statement correct since the capacity() function is declared as private?
			theTrees.resize(BQ.capacity());
		treeNum = BQ.capacity();
		for(int i=0; i<treeNum; i++)
			theTrees.push_back(clone(BQ.theTrees[i]));
	}

	~BinomialQueue(){
		treeNum = 0;
		for(int i=0; i<theTrees.size(); i++)
			makeEmpty(theTrees[i]);
		theTrees.clear();
	}

	bool isEmpty(){
		return treeNum == 0;
	}

	void merge(BinomialQueue & rhs){
		if(this == &rhs)
			return;

		// confused about the implementation
		// to be continued...
	}
	
private:
	vector<BinomialNode *> theTrees;
	int treeNum;
	
	int capacity() const {
		return treeNum;
	}

	BinomialNode * clone(BinomialNode * root)	{
		if(root == NULL)
			return NULL;

		return new BinomialNode(root->val, clone(root->firstChild), clone(root->nextSibling));
	}

	void makeEmpty(BinomialNode * root){
		if(root == NULL)
			return;

		makeEmpty(root->firstChild);
		makeEmpty(root->nextSibling);
		delete root;
		root = NULL;
	}

	//merge two binomialTrees of the same size
	//time complexity: O(1)
	BinomialNode * mergeTree(BinomialNode * first, BinomialNode * second)
	{
		if(first == NULL || second == NULL)            //This situation should not occur.
			return NULL;
		
		if(first->val <= second->val){
			second->nextSibling = first->firstChild;
			first->firstChild = second;
			return first;
		}
		else
			return mergeTree(second, first);
	}
};