class Solution {
  public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> m;
		for (size_t i = 0; i < nums.size(); ++i) {
			const int diff = target - nums[i];
			if (m.contains(diff)) {
				return {m[diff], static_cast<int>(i)};
			}
			m.insert({nums[i], i});
		}
		return {};
	}
};
