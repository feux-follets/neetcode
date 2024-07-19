class Solution {
  public:
	int m;
	int n;

	bool exist(vector<vector<char>>& board, string word) {
		m = board.size();
		n = board[0].size();
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[i].size(); ++j) {
				if (board[i][j] == word.front()) {
					if (dfs(board, word, 0, i, j))
						return true;
				}
			}
		}
		return false;
	}

	bool dfs(vector<vector<char>>& board, const string& word, const int index, const int i, const int j) {
		if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index])
			return false;
		if (index == word.size() - 1)
			return true;

		board[i][j] = '#';
		if (dfs(board, word, index + 1, i - 1, j) || dfs(board, word, index + 1, i + 1, j) ||
			dfs(board, word, index + 1, i, j - 1) || dfs(board, word, index + 1, i, j + 1)) {
			return true;
		}
		board[i][j] = word[index];
		return false;
	}
};
