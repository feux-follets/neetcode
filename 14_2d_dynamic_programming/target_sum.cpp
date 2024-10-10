class Solution {
  public:
	int findTargetSumWays(vector<int>& nums, int target) {
		const int n = nums.size();
		const int sum = accumulate(nums.begin(), nums.end(), 0);
		if (target > sum)
			return 0;
		const int sum_pos = (target + sum) / 2;
		if ((target + sum) % 2 || sum_pos < 0)
			return 0;
		vector<int> dp(sum_pos + 1, 0);
		dp[0] = 1;
		// Combination, loop elements first
		for (const int num : nums) {
			// Loop target
			for (int i = sum_pos; i >= num; --i) {
				// How many ways I can sum with the extra num
				dp[i] = dp[i] + dp[i - num];
			}
		}
		return dp[sum_pos];
	}
};
