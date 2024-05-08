class Solution {
  public:
	int goodNodes(TreeNode* root) {
		int result = 1;

		queue<pair<TreeNode*, int>> q;

		q.emplace(root, root->val);
		while (!q.empty()) {
			int count = q.size();
			for (int i = 0; i < count; ++i) {
				auto curr = q.front();
				q.pop();

				if (curr.first->left) {
					if (curr.first->left->val >= curr.second)
						result++;
					q.emplace(curr.first->left, std::max(curr.first->left->val, curr.second));
				}
				if (curr.first->right) {
					if (curr.first->right->val >= curr.second)
						result++;
					q.emplace(curr.first->right, std::max(curr.first->right->val, curr.second));
				}
			}
		}

		return result;
	}
};

class Solution {
  public:
	int goodNodes(TreeNode* root) {
		int result = 0;
		dfs(root, INT_MIN, result);
		return result;
	}

	void dfs(TreeNode* root, const int curr_max, int& result) {
		if (!root)
			return;

		if (root->val >= curr_max)
			++result;

		dfs(root->left, std::max(curr_max, root->val), result);
		dfs(root->right, std::max(curr_max, root->val), result);
	}
};
