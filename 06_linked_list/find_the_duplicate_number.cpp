class Solution {
  public:
	int findDuplicate(vector<int>& nums) {
		std::size_t slow = nums[0];
		std::size_t fast = nums[0];
		while (true) {
			slow = nums[slow];
			fast = nums[nums[fast]];
			if (slow == fast)
				break;
		}
		std::size_t slow_2 = nums[0];
		while (true) {
			if (slow == slow_2)
				return slow;
			slow = nums[slow];
			slow_2 = nums[slow_2];
		}
	}
};
