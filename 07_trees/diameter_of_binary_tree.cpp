class Solution {
  public:
	int diameterOfBinaryTree(TreeNode* root) {
		int diameter = 0;
		dfs(root, diameter);
		return diameter;
	}

	int dfs(TreeNode* root, int& diameter) {
		if (!root)
			return 0;

		int left_edge = dfs(root->left, diameter);
		int right_edge = dfs(root->right, diameter);

		diameter = std::max(diameter, left_edge + right_edge);

		return 1 + max(left_edge, right_edge);
	}
};
