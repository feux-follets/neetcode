class Solution {
  public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		// Both null
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
