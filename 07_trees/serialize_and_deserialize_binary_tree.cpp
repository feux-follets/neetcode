class Codec {
  public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		std::ostringstream out;
		encode(root, out);
		return out.str();
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		std::istringstream in(data);
		return decode(in);
	}

  private:
	void encode(TreeNode* root, std::ostringstream& out) {
		// Use as separator for stream
		if (root == nullptr) {
			out << "# ";
			return;
		}
		out << root->val << " ";
		encode(root->left, out);
		encode(root->right, out);
	}

	TreeNode* decode(std::istringstream& in) {
		std::string token;
		in >> token;
		if (token == "#")
			return nullptr;

		auto node = new TreeNode(std::stoi(token));
		node->left = decode(in);
		node->right = decode(in);

		return node;
	}
};
