class Trie {
	struct Node {
		std::array<Node*, 26> child;
		bool is_word = false;
	};

  public:
	Node* root;

	Trie() { root = new Node(); }

	void insert(string word) {
		auto p = root;
		int index = 0;
		for (const char c : word) {
			index = c - 'a';
			if (p->child[index] == nullptr) {
				p->child[index] = new Node();
			}
			p = p->child[index];
		}
		p->is_word = true;
	}

	bool search(string word) {
		auto p = root;
		int index = 0;
		for (const char c : word) {
			index = c - 'a';
			if (p->child[index] == nullptr) {
				return false;
			}
			p = p->child[index];
		}
		return p->is_word;
	}

	bool startsWith(string prefix) {
		auto p = root;
		for (const char c : prefix) {
			auto index = c - 'a';
			if (p->child[index] == nullptr) {
				return false;
			}
			p = p->child[index];
		}
		return true;
	}
};
