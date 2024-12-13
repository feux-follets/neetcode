// Time: O(n)
// Space: O(1)

class Solution {
  public:
	int majorityElement(vector<int>& nums) {
		// Boyer-Moore Voting Algorithm
		int result = 0;
		int count = 0;

		for (int i = 0; i < nums.size(); ++i) {
			if (count == 0)
				result = nums[i];
			count += result == nums[i] ? 1 : -1;
		}
		return result;
	}
};
