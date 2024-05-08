class Solution {
  public:
	bool isSubtree(TreeNode* root, TreeNode* subRoot) {
		if (!root)
			return false;
		if (isSameTree(root, subRoot))
			return true;
		return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
	}

	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (!p && !q)
			return true;
		// Either one null
		if (!p || !q)
			return false;
		// Different value
		if (p->val != q->val)
			return false;

		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};
