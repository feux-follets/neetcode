class Solution {
  public:
	int rob(vector<int>& nums) {
		if (nums.size() == 1)
			return nums[0];

		// Rob [0,...,n-2]
		int first = rob(nums, 0, nums.size() - 1);
		// Rob [1,...,n-1]
		int second = rob(nums, 1, nums.size());

		return max(first, second);
	}

	int rob(vector<int>& nums, int begin, int end) {
		int curr = 0;
		int prev = 0;
		int next = 0;

		for (int i = begin; i < end; ++i) {
			next = max(nums[i] + prev, curr);
			prev = curr;
			curr = next;
		}

		return curr;
	}
};
