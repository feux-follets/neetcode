class Solution {
  public:
	int m;
	int n;
	std::vector<std::pair<int, int>> directions {
		{ 1,	0},
		{-1,	 0},
		 { 0,	 1},
		 { 0, -1}
	};

	int orangesRotting(vector<vector<int>>& grid) {
		m = grid.size();
		n = grid.front().size();

		std::queue<std::pair<int, int>> q;

		int fresh = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 2)
					q.emplace(i, j);
				if (grid[i][j] == 1)
					fresh++;
			}
		}
		if (fresh == 0)
			return 0;
		if (q.empty())
			return -1;
		int result = -1;
		while (!q.empty()) {
			int size = q.size();
			while (size--) {
				const int row = q.front().first;
				const int col = q.front().second;
				q.pop();

				for (const auto& d : directions) {
					const int x = row + d.first;
					const int y = col + d.second;

					if (x < 0 || y < 0 || x >= m || y >= n || grid[x][y] == 0 || grid[x][y] == 2)
						continue;
					fresh--;
					grid[x][y] = 2;
					q.emplace(x, y);
				}
			}
			// Processed all current level
			result++;
		}
		if (fresh)
			return -1;

		return result;
	}
};
