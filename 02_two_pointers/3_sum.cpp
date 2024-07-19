class Solution {
  public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		auto n = nums.size();
		for (int i = 0; i < n - 2; ++i) {
			if (nums[i] > 0)
				break;
			if (i > 0 && nums[i - 1] == nums[i]) {
				continue;
			}
			auto j = i + 1;
			auto k = n - 1;
			while (j < k) {
				auto sum = nums[i] + nums[j] + nums[k];
				if (sum > 0)
					--k;
				else if (sum < 0)
					++j;
				else {
					result.push_back({nums[i], nums[j], nums[k]});
					while (j < k && nums[j] == nums[j + 1])
						++j;
					++j;
					while (j < k && nums[k] == nums[k - 1])
						--k;
					--k;
				}
			}
		}
		return result;
	}
};
