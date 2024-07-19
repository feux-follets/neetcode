class Solution {
  public:
	vector<int> rightSideView(TreeNode* root) {
		if (!root)
			return {};
		vector<int> result;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int count = q.size();
			for (int i = 0; i < count; ++i) {
				// push the rightmost first
				TreeNode* curr = q.front();
				q.pop();
				if (i == 0)
					result.push_back(curr->val);
				if (curr->right)
					q.push(curr->right);
				if (curr->left)
					q.push(curr->left);
			}
		}
		return result;
	}
};
