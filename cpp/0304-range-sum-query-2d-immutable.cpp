// Time: O(1)
// Space: O(m*n)

class NumMatrix {
  public:
	NumMatrix(vector<vector<int>>& matrix) {
		const int m = matrix.size();
		const int n = matrix.front().size();
		prefix_sum = vector(m + 1, vector(n + 1, 0));
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				prefix_sum[i][j] =
					matrix[i - 1][j - 1] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		return prefix_sum[row2 + 1][col2 + 1] + prefix_sum[row1][col1] - prefix_sum[row2 + 1][col1] -
			   prefix_sum[row1][col2 + 1];
	}

  private:
	vector<vector<int>> prefix_sum; // prefix_sum[i+1][j+1] = matrix sum from [0,0] to [i,j]
};
