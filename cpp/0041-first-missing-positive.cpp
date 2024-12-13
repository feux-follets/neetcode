// Time: O(n)
// Space: O(1)

class Solution {
  public:
	int firstMissingPositive(vector<int>& nums) {
		const int n = nums.size();
		int i = 0;

		while (i < nums.size()) {
			if (nums[i] <= 0 || nums[i] > n) {
				++i;
				continue;
			}
			if (nums[i] != nums[nums[i] - 1]) {
				std::swap(nums[i], nums[nums[i] - 1]);
			} else {
				++i;
			}
		}
		for (i = 0; i < nums.size(); ++i) {
			if (nums[i] != i + 1)
				return i + 1;
		}
		return n + 1;
	}
};
