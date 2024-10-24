class Solution {
  public:
	bool canJump(vector<int>& nums) {
		const int n = nums.size();
		int reachable = 0;

		for (int i = 0; i < n; ++i) {
			if (reachable < i)
				return false;
			reachable = max(reachable, i + nums[i]);
			if (reachable >= n - 1)
				return true;
		}
		return false;
	}
};
