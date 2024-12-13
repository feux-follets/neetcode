// Time: O(n^2)
// Space: O(n)

class Solution {
  public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int rows[9] {};
		int cols[9] {};
		int grids[9] {};

		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.')
					continue;
				const int value = board[i][j] - '1';
				if (rows[i] & (1 << value) || cols[j] & (1 << value) || grids[i / 3 * 3 + j / 3] & (1 << value))
					return false;
				rows[i] |= (1 << value);
				cols[j] |= (1 << value);
				grids[i / 3 * 3 + j / 3] |= (1 << value);
			}
		}
		return true;
	}
};
