class Solution {
  public:
	unordered_set<int> cols;
	unordered_set<int> neg_diagnals;
	unordered_set<int> pos_diagnals;

	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;
		vector<string> board(n, string(n, '.'));
		backtrack(result, board, n, 0);
		return result;
	}

	void backtrack(vector<vector<string>>& result, vector<string>& board, const int n, const int row) {
		if (n == row) {
			result.push_back(board);
			return;
		}
		for (int col = 0; col < n; ++col) {
			if (cols.contains(col) || neg_diagnals.contains(row - col) || pos_diagnals.contains(row + col))
				continue;

			cols.insert(col);
			neg_diagnals.insert(row - col);
			pos_diagnals.insert(row + col);
			board[row][col] = 'Q';
			backtrack(result, board, n, row + 1);

			cols.erase(col);
			neg_diagnals.erase(row - col);
			pos_diagnals.erase(row + col);
			board[row][col] = '.';
		}
	}
};

class Solution {
  public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;
		vector<string> board(n, std::string(n, '.'));
		backtrack(result, board, 0, n);
		return result;
	}

	void backtrack(vector<vector<string>>& result, vector<string>& board, const int row, const int n) {
		if (row == n) {
			result.push_back(board);
			return;
		}

		for (int j = 0; j < n; ++j) {
			if (!can_place(board, row, j, n))
				continue;
			board[row][j] = 'Q';
			backtrack(result, board, row + 1, n);
			board[row][j] = '.';
		}
	}

	bool can_place(const vector<string>& board, const int row, const int col, const int n) {
		// Check every row with same col
		for (int i = 0; i < n; ++i) {
			if (board[i][col] == 'Q')
				return false;
			const int left_x = col - i;
			const int right_x = col + i;
			const int upper_y = row - i;
			const int lower_y = row + i;
			if (left_x >= 0 && upper_y >= 0 && board[upper_y][left_x] == 'Q')
				return false;
			if (right_x < n && upper_y >= 0 && board[upper_y][right_x] == 'Q')
				return false;
			if (left_x >= 0 && lower_y < n && board[lower_y][left_x] == 'Q')
				return false;
			if (right_x < n && lower_y < n && board[lower_y][right_x] == 'Q')
				return false;
		}

		return true;
	}
};
