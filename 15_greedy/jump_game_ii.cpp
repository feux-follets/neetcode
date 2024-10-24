class Solution {
  public:
	int jump(vector<int>& nums) {
		const int n = nums.size();
		int result = 0;
		int max_reach = 0;
		int jump_window_end = 0;
		for (int i = 0; i < n - 1; ++i) {
			max_reach = max(max_reach, i + nums[i]);
			if (max_reach >= n - 1)
				return result + 1;
			if (i == jump_window_end) {
				jump_window_end = max_reach;
				result++;
			}
		}
		return result;
	}
};
