#include <algorithm>

class Solution {
  public:
	vector<int> getConcatenation(vector<int>& nums) {
		const auto N = nums.size();
		vector<int> result(2 * N);
		ranges::copy(nums, result.begin());
		ranges::copy(nums, result.begin() + N);
		return result;
	}
};
