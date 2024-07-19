class Solution {
  public:
	int kthSmallest(TreeNode* root, int k) {
		int result = 0;
		inorder(root, k, result);
		return result;
	}

	void inorder(TreeNode* root, int& k, int& result) {
		if (root == nullptr)
			return;

		inorder(root->left, k, result);
		if (k-- == 1) {
			result = root->val;
			return;
		}
		inorder(root->right, k, result);
	}
};
