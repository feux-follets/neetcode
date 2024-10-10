class Solution {
  public:
	int numDistinct(string s, string t) {
		const int m = s.size();
		const int n = t.size();
		vector<unsigned> dp(n + 1, 0);
		dp[0] = 1;

		for (int i = 1; i <= m; ++i) {
			// Always 1 for empty t
			int prev = 1;
			for (int j = 1; j <= n; ++j) {
				// Read j-1 value
				int temp = dp[j];
				if (s[i - 1] == t[j - 1])
					dp[j] += prev;
				// Write j-1 value
				prev = temp;
			}
		}
		return dp[n];
	}
};
