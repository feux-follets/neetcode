class Solution {
  public:
	int maxPathSum(TreeNode* root) {
		int result = INT_MIN;
		dfs(root, result);
		return result;
	}

	int dfs(TreeNode* root, int& result) {
		if (root == nullptr)
			return 0;

		int left = std::max(dfs(root->left, result), 0);
		int right = std::max(dfs(root->right, result), 0);

		int cur_path = root->val + left + right;
		result = std::max(result, cur_path);

		return root->val + std::max(left, right);
	}
};
