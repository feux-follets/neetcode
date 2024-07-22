class Solution {
  public:
	int m;
	int n;

	vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
		m = heights.size();
		n = heights.front().size();

		vector<vector<int>> result;
		vector<vector<bool>> pacific(m, vector<bool>(n));
		vector<vector<bool>> atlantic(m, vector<bool>(n));

		for (int j = 0; j < n; ++j) {
			dfs(0, j, pacific, heights);
			dfs(m - 1, j, atlantic, heights);
		}
		for (int i = 0; i < m; ++i) {
			dfs(i, 0, pacific, heights);
			dfs(i, n - 1, atlantic, heights);
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (pacific[i][j] && atlantic[i][j])
					result.emplace_back(std::vector {i, j});
			}
		}

		return result;
	}

	void dfs(const int i, const int j, vector<vector<bool>>& visited, const vector<vector<int>>& heights) {
		visited[i][j] = true;

		if (i > 0 && !visited[i - 1][j] && heights[i - 1][j] >= heights[i][j])
			dfs(i - 1, j, visited, heights);
		if (i < m - 1 && !visited[i + 1][j] && heights[i + 1][j] >= heights[i][j])
			dfs(i + 1, j, visited, heights);
		if (j > 0 && !visited[i][j - 1] && heights[i][j - 1] >= heights[i][j])
			dfs(i, j - 1, visited, heights);
		if (j < n - 1 && !visited[i][j + 1] && heights[i][j + 1] >= heights[i][j])
			dfs(i, j + 1, visited, heights);
	}
};
