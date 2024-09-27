class Solution {
  public:
	int lengthOfLIS(vector<int>& nums) {
		const int n = nums.size();
		vector<int> dp(n, 1);
		int result = 1;

		for (int i = n - 2; i >= 0; --i) {
			for (int j = i + 1; j < n; ++j) {
				if (nums[i] < nums[j]) {
					dp[i] = max(1 + dp[j], dp[i]);
				}
			}
			result = max(result, dp[i]);
		}

		return result;
	}
};

class Solution {
  public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> result;

		for (int i = 0; i < nums.size(); ++i) {
			auto it = lower_bound(result.begin(), result.end(), nums[i]);
			if (it == result.end()) {
				result.push_back(nums[i]);
			} else {
				*it = nums[i];
			}
		}
		return result.size();
	}
};
