class Solution {
  public:
	bool canPartition(vector<int>& nums) {
		const int total = accumulate(nums.begin(), nums.end(), 0);
		if (total & 1)
			return false;
		const int half = total / 2;

		vector<bool> dp(half + 1, false);
		dp[0] = true;

		for (const int num : nums) {
			for (int target = half; target >= num; --target) {
				dp[target] = dp[target] || dp[target - num];
			}
		}

		return dp[half];
	}
};
