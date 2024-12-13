// Time: O(n)
// Space: O(1)

class Solution {
  public:
	int removeElement(vector<int>& nums, int val) {
		int result {};

		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] != val) {
				nums[result++] = nums[i];
			}
		}

		return result;
	}
};
