class Solution {
  public:
	int maxDepth(TreeNode* root) {
		if (!root)
			return 0;

		return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
	}
};

class Solution {
  public:
	int maxDepth(TreeNode* root) {
		if (!root)
			return 0;

		queue<TreeNode*> q;
		q.push(root);
		int depth = 0;
		while (!q.empty()) {
			const int count = q.size();
			for (int i = 0; i < count; ++i) {
				TreeNode* node = q.front();
				q.pop();
				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}
			++depth;
		}
		return depth;
	}
};
