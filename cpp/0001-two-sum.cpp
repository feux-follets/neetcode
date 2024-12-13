// Time: O(n)
// Space: O(n)

class Solution {
  public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> m;

		for (int i = 0; i < nums.size(); i++) {
			const int t = target - nums[i];
			if (m.contains(t)) {
				return {m[t], i};
			}
			m[nums[i]] = i;
		}
		return {};
	}
};
