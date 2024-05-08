class Solution {
  public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (!root)
			return {};
		vector<vector<int>> result;

		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int count = q.size();
			vector<int> level;
			for (int i = 0; i < count; ++i) {
				TreeNode* curr = q.front();
				q.pop();

				level.push_back(curr->val);
				if (curr->left)
					q.push(curr->left);
				if (curr->right)
					q.push(curr->right);
			}
			result.push_back(level);
		}

		return result;
	}
};
