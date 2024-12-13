// Time: O(n) Average O(n^2) Worst
// Space: O(log(n))

class Solution {
  public:
	vector<int> sortArray(vector<int>& nums) {
		quick_sort(nums, 0, nums.size() - 1);
		return nums;
	}

	void quick_sort(vector<int>& nums, int left, int right) {
		// 2 or fewer elements
		if (right <= left + 1) {
			if (right == left + 1 && nums[right] < nums[left]) {
				std::swap(nums[left], nums[right]);
			}
			return;
		}
		int pivot_index = hoare_partition(nums, left, right);
		quick_sort(nums, left, pivot_index - 1);
		quick_sort(nums, pivot_index + 1, right);
	}

	int hoare_partition(vector<int>& nums, int left, int right) {
		// left <= mid <= right after swap
		int mid = (left + right) >> 1;
		if (nums[left] > nums[right]) {
			std::swap(nums[left], nums[right]);
		}
		if (nums[mid] > nums[right]) {
			std::swap(nums[mid], nums[right]);
		}
		if (nums[left] > nums[mid]) {
			std::swap(nums[left], nums[mid]);
		}
		// Put mid element at left+1 for easier partition
		std::swap(nums[mid], nums[left + 1]);
		int pivot = nums[left + 1];
		int i = left + 1;
		int j = right;
		while (true) {
			while (nums[++i] < pivot)
				;
			while (nums[--j] > pivot)
				;
			if (i > j)
				break;
			// i : element larger or equal to pivot
			// j : element smaller or equal to pivot
			std::swap(nums[i], nums[j]);
		}
		nums[left + 1] = nums[j];
		nums[j] = pivot;

		return j;
	}
};
