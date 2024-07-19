class Solution {
  public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> result;
		vector<int> curr;
		backtrack(result, curr, nums, 0);
		return result;
	}

	void backtrack(vector<vector<int>>& result, vector<int>& curr, const vector<int>& nums, int start) {
		result.push_back(curr);
		for (int i = start; i < nums.size(); ++i) {
			curr.push_back(nums[i]);
			backtrack(result, curr, nums, i + 1);
			curr.pop_back();
		}
	}
};
