class Solution {
  public:
	int maxSubArray(vector<int>& nums) {
		int curr = nums[0];
		int result = curr;

		for (int i = 1; i < nums.size(); ++i) {
			curr = max(curr + nums[i], nums[i]);
			result = max(result, curr);
		}

		return result;
	}
};
