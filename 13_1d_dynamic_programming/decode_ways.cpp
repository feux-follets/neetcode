class Solution {
  public:
	int numDecodings(string s) {
		if (s[0] == '0')
			return 0;
		const int n = s.size();
		vector<int> dp(n + 1, 0);

		dp[0] = 1;
		dp[1] = 1;

		for (int i = 2; i <= n; ++i) {
			int one = s[i - 1] - '0';
			int two = (s[i - 2] - '0') * 10 + one;

			if (one != 0)
				dp[i] += dp[i - 1];

			if (two >= 10 && two <= 26)
				dp[i] += dp[i - 2];
		}
		return dp[n];
	}
};
