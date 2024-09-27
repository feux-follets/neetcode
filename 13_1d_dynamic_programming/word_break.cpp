class Solution {
  public:
	bool wordBreak(string s, vector<string>& wordDict) {
		const int n = s.size();
		unordered_set<string> dict(wordDict.begin(), wordDict.end());
		vector<bool> dp(n + 1, false);

		dp[0] = true;
		for (int i = 1; i <= n; ++i) {
			for (int j = i - 1; j >= 0; --j) {
				if (dp[j]) {
					string word = s.substr(j, i - j);
					if (dict.contains(word)) {
						dp[i] = true;
						break;
					}
				}
			}
		}
		return dp[n];
	}
};
