class Solution {
  public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> m;
		for (int i = 0; i < nums.size(); ++i) {
			if (m.contains(target - nums[i]))
				return {i, m.at(target - nums[i])};
			m.emplace(nums[i], i);
		}

		return {};
	}
};
