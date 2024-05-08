class Solution {
  public:
	int findMin(vector<int>& nums) {
		int result {nums[0]};
		int low = 0;
		int high = nums.size() - 1;
		while (low <= high) {
			if (nums[low] < nums[high]) {
				result = min(result, nums[low]);
				break;
			}
			const int mid = low + (high - low) / 2;
			result = min(nums[mid], result);
			if (nums[high] < result)
				low = mid + 1;
			else
				high = mid - 1;
		}
		return result;
	}
};
