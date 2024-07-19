class WordDictionary {
	struct Node {
		std::array<Node*, 26> childs;
		bool is_word = false;
	};

	Node* root;

  public:
	WordDictionary() : root(new Node()) {}

	void addWord(string word) {
		Node* p = root;
		for (const char c : word) {
			const int index = c - 'a';
			if (p->childs[index] == nullptr)
				p->childs[index] = new Node();
			p = p->childs[index];
		}
		p->is_word = true;
	}

	bool search(string word) { return search_in_node(word, 0, root); }

	bool search_in_node(const string& word, int i, Node* node) {
		if (node == nullptr)
			return false;
		if (i == word.size())
			return node->is_word;
		if (word[i] != '.')
			return search_in_node(word, i + 1, node->childs[word[i] - 'a']);
		for (int j = 0; j < 26; ++j) {
			if (search_in_node(word, i + 1, node->childs[j]))
				return true;
		}
		return false;
	}
};
