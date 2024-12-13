class Solution {
  public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> result;
		return ranges::any_of(nums, [&result](int num) { return !result.insert(num).second; });
	}
};
