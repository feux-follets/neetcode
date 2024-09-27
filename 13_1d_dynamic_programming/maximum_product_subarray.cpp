class Solution {
  public:
	int maxProduct(vector<int>& nums) {
		int result = nums[0];
		int dp_max = result;
		int dp_min = result;

		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] < 0)
				swap(dp_max, dp_min);

			dp_max = max(nums[i], dp_max * nums[i]);
			dp_min = min(nums[i], dp_min * nums[i]);
			result = max(result, dp_max);
		}

		return result;
	}
};
