class Solution {
  public:
	int search(vector<int>& nums, int target) {
		int beg = 0;
		int end = nums.size() - 1;

		while (beg <= end) {
			const int mid = beg + (end - beg) / 2;
			if (nums[mid] == target)
				return mid;
			if (nums[beg] <= nums[mid]) {
				// Left is sorted
				if (nums[mid] > target && nums[beg] <= target)
					end = mid - 1;
				else
					beg = mid + 1;
			} else {
				// Right is sorted
				if (nums[mid] < target && nums[end] >= target)
					beg = mid + 1;
				else
					end = mid - 1;
			}
		}
		return -1;
	}
};
