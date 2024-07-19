class Solution {
  public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		backtrack(nums, 0, result);
		return result;
	}

	void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
		if (start == nums.size()) {
			result.push_back(nums);
			return;
		}
		for (int i = start; i < nums.size(); i++) {
			swap(nums[i], nums[start]);
			backtrack(nums, start + 1, result);
			swap(nums[i], nums[start]);
		}
	}
};
