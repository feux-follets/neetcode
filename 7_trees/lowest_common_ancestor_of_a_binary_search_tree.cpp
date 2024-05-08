class Solution {
  public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode* result = root;
		while (true) {
			if (p->val < result->val && q->val < result->val)
				result = result->left;
			else if (p->val > result->val && q->val > result->val)
				result = result->right;
			else
				break;
		}
		return result;
	}
};
