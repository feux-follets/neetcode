class Solution {
  public:
	bool isValidSudoku(vector<vector<char>>& board) {
		const std::size_t n = 9;
		int row[n][n] {}, col[n][n] {}, grid[n][n] {};

		int grid_num {}, num {};
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (board[i][j] == '.')
					continue;
				grid_num = i / 3 * 3 + j / 3;
				num = board[i][j] - '1';
				if (row[i][num] || col[j][num] || grid[grid_num][num])
					return false;
				row[i][num] = col[j][num] = grid[grid_num][num] = 1;
			}
		}
		return true;
	}
};
