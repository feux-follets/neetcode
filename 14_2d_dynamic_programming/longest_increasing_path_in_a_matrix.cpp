class Solution {
  public:
	const vector<vector<int>> directions {
		{ 0,	1},
		{ 1,	0},
		{ 0, -1},
		 {-1,  0}
	};

	int longestIncreasingPath(vector<vector<int>>& matrix) {
		const int m = matrix.size();
		const int n = matrix.front().size();
		vector<vector<int>> dp(m, vector<int>(n, 0));

		int result = 0;

		function<int(int, int)> dfs = [&](int i, int j) {
			if (dp[i][j] != 0)
				return dp[i][j];

			dp[i][j] = 1;
			for (const auto& direction : directions) {
				const int x = i + direction[0];
				const int y = j + direction[1];
				if (x >= 0 && y >= 0 && x < m && y < n && matrix[x][y] > matrix[i][j]) {
					dp[i][j] = max(dp[i][j], 1 + dfs(x, y));
				}
			}
			return dp[i][j];
		};

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				result = max(result, dfs(i, j));
			}
		}

		return result;
	}
};
