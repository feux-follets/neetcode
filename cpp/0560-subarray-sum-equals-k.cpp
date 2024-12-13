// Time: O(n)
// Space: O(n)

class Solution {
  public:
	int subarraySum(vector<int>& nums, int k) {
		unordered_map<int, int> prefix_sums;
		prefix_sums[0] = 1;
		int result = 0;
		int sum = 0;
		for (const int num : nums) {
			sum += num;
			if (prefix_sums.contains(sum - k)) {
				result += prefix_sums[sum - k];
			}
			prefix_sums[sum]++;
		}
		return result;
	}
};
