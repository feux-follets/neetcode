class Solution {
  public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr)
			return nullptr;

		TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};

class Solution {
  public:
	TreeNode* invertTree(TreeNode* root) {
		if (root == nullptr)
			return nullptr;

		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode* curr = q.front();
			q.pop();
			TreeNode* temp = curr->left;
			curr->left = curr->right;
			curr->right = temp;

			if (curr->left) {
				q.push(curr->left);
			}
			if (curr->right) {
				q.push(curr->right);
			}
		}
		return root;
	}
};
