class Solution {
  public:
	bool isValidBST(TreeNode* root) {
		if (!root)
			return true;
		return check(root, LONG_MIN, LONG_MAX);
	}

	bool check(TreeNode* root, const long left, const long right) {
		if (!root)
			return true;
		if (root->val > left && root->val < right) {
			return check(root->left, left, root->val) && check(root->right, root->val, right);
		}
		return false;
	}
};
