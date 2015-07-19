//Lowest Common Ancestor of a Binary Tree: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
/****************************************************************************************************************
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: ¡°The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).¡±
*******************************************************************************************************************/

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	vector<TreeNode *> pAncestor;
	vector<TreeNode *> qAncestor;
	pAncestor.clear();
	qAncestor.clear();
	isAncestor(root, p, pAncestor);
	isAncestor(root, q, qAncestor);
	if(pAncestor.empty() || qAncestor.empty()){
		return NULL;
	}
	else{
		TreeNode * res = root;
		for(int i=pAncestor.size()-1, j=qAncestor.size()-1; i>=0 && j>=0; i--, j--){
			if(pAncestor[i] == qAncestor[j])
				res = pAncestor[i];
		}
		return res;
	}
}

bool isAncestor(TreeNode * root, TreeNode * p, vector<TreeNode *> & ancestor){
	if(root == NULL)
		return false;
	if(root == p){
		ancestor.push_back(root);
		return true;
	}

	bool res = false;
	if(isAncestor(root->left, p, ancestor)){
		res = true;
	}
	else if(isAncestor(root->right, p, ancestor)){
		res = true;
	}

	if(res)
		ancestor.push_back(root);

	return res;
}