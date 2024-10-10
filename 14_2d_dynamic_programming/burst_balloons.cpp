class Solution {
  public:
	int maxCoins(vector<int>& nums) {
		// Add one to front and back
		const int n = nums.size();
		nums.insert(nums.begin(), 1);
		nums.push_back(1);
		vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

		for (int length = 1; length <= n; ++length) {
			for (int left = 1; left <= n - length + 1; ++left) {
				int right = left + length - 1;
				for (int i = left; i <= right; ++i) {
					dp[left][right] = max(dp[left][right], nums[left - 1] * nums[i] * nums[right + 1] +
															   dp[left][i - 1] + dp[i + 1][right]);
				}
			}
		}
		return dp[1][n];
	}
};
