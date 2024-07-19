class Solution {
	struct TrieNode {
		std::array<TrieNode*, 26> childs;
		bool is_word = false;
		std::string word;
	};

  public:
	TrieNode* root = new TrieNode();
	int m;
	int n;

	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		for (const auto& word : words) {
			insert(word);
		}
		m = board.size();
		n = board.front().size();
		vector<string> result;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				dfs(board, result, i, j, root);
			}
		}
		return result;
	}

	void insert(string word) {
		auto p = root;
		int index = 0;
		for (const char c : word) {
			index = c - 'a';
			if (p->childs[index] == nullptr) {
				p->childs[index] = new TrieNode();
			}
			p = p->childs[index];
		}
		p->is_word = true;
		p->word = word;
	}

	void dfs(vector<vector<char>>& board, vector<string>& result, const int i, const int j, TrieNode* node) {
		if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '#')
			return;

		const char c = board[i][j];
		int index = c - 'a';
		node = node->childs[index];
		if (node == nullptr)
			return;

		if (node->is_word) {
			result.push_back(node->word);
			node->is_word = false;
		}

		board[i][j] = '#';
		dfs(board, result, i + 1, j, node);
		dfs(board, result, i - 1, j, node);
		dfs(board, result, i, j + 1, node);
		dfs(board, result, i, j - 1, node);
		board[i][j] = c;
	}
};
