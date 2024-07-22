class Solution {
  public:
	int m;
	int n;
	const int INF = 2147483647;

	vector<pair<int, int>> direction {
		{ 1,	0},
		{-1,	 0},
		 { 0,	 1},
		 { 0, -1}
	};

	void islandsAndTreasure(vector<vector<int>>& grid) {
		m = grid.size();
		n = grid.front().size();

		std::queue<std::pair<int, int>> q;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 0) {
					q.emplace(i, j);
				}
			}
		}
		while (!q.empty()) {
			const int row = q.front().first;
			const int col = q.front().second;
			q.pop();

			for (const auto& d : direction) {
				const int next_row = row + d.first;
				const int next_col = col + d.second;

				if (next_row < 0 || next_col < 0 || next_row >= m || next_col >= n ||
					grid[next_row][next_col] != INT_MAX)
					continue;

				grid[next_row][next_col] = grid[row][col] + 1;
				q.emplace(next_row, next_col);
			}
		}
	}
};
