class Solution {
  public:
	int uniquePaths(int m, int n) {
		long long result = 1;
		for (int i = 1; i <= m - 1; ++i) {
			result = result * (n - 1 + i) / i;
		}
		return result;
	}
};

class Solution {
  public:
	int uniquePaths(int m, int n) {
		vector<int> cur(n, 1);
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				cur[j] += cur[j - 1];
			}
		}
		return cur[n - 1];
	}
};
