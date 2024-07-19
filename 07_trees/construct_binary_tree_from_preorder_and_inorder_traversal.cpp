class Solution {
  public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int root_index = 0;
		return build(preorder, inorder, root_index, 0, preorder.size() - 1);
	}

	TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& root_index, int start, int end) {
		if (start > end)
			return nullptr;

		TreeNode* root = new TreeNode(preorder[root_index]);
		// Locate root in inorder
		int pos = std::find(inorder.begin() + start, inorder.begin() + end, root->val) - inorder.begin();

		// Build subtrees
		root_index++;
		root->left = build(preorder, inorder, root_index, start, pos - 1);
		root->right = build(preorder, inorder, root_index, pos + 1, end);

		return root;
	}
};
