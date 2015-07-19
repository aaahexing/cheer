//Lowest Common Ancestor of a Binary Search Tree: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
/**************************************************************************************
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: ¡°The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).¡±
***************************************************************************************/

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//time complexity: O(h)
//h is the max of p's depth and q's depth
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	vector<TreeNode *> pAncestor;
	vector<TreeNode *> qAncestor;
	pAncestor.clear();
	qAncestor.clear();

	TreeNode * tmp = root;
	while(tmp != p && tmp != NULL){
		pAncestor.push_back(tmp);
		if(p->val < tmp->val)
			tmp = tmp->left;
		else if(p->val > tmp->val)
			tmp = tmp->right;
		else
			break;
	}
	pAncestor.push_back(tmp);
	if(!tmp)
		return NULL;

	tmp = root;
	while(tmp != q){
		qAncestor.push_back(tmp);
		if(q->val < tmp->val)
			tmp = tmp->left;
		else if(q->val > tmp->val)
			tmp = tmp->right;
		else
			break;
	}
	qAncestor.push_back(tmp);
	if(!tmp)
		return NULL;

	TreeNode * res;
	for(int i=0; i<pAncestor.size() && i<qAncestor.size(); i++){
		if(pAncestor[i] == qAncestor[i])
			res = pAncestor[i];
		else
			break;
	}

	return res;
}