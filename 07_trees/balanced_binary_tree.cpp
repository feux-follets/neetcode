class Solution {
  public:
	bool isBalanced(TreeNode* root) {
		bool result = true;
		dfs(root, result);
		return result;
	}

	int dfs(TreeNode* root, bool& result) {
		if (!root || !result)
			return 0;

		int left_height = dfs(root->left, result);
		if (!result)
			return 0;
		int right_height = dfs(root->right, result);
		if (!result)
			return 0;

		if (abs(left_height - right_height) > 1) {
			result = false;
		}
		return 1 + max(left_height, right_height);
	}
};
