class Solution {
  public:
	int m;
	int n;

	int numIslands(vector<vector<char>>& grid) {
		int result = 0;
		m = grid.size();
		n = grid.front().size();
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == '1') {
					dfs(grid, i, j);
					result++;
				}
			}
		}

		return result;
	}

	void dfs(vector<vector<char>>& grid, const int i, const int j) {
		if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == '0')
			return;
		grid[i][j] = '0';
		dfs(grid, i + 1, j);
		dfs(grid, i - 1, j);
		dfs(grid, i, j + 1);
		dfs(grid, i, j - 1);
	}
};
