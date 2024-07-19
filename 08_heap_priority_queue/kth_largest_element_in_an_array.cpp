class Solution {
  public:
	std::random_device rd;
	std::mt19937 gen = std::mt19937(rd()); // Mersenne Twister engine

	int findKthLargest(vector<int>& nums, int k) {
		k = nums.size() - k;
		int pivot_index = nums.size();
		int left = 0;
		int right = nums.size() - 1;
		while (pivot_index != k) {
			pivot_index = quick_select(nums, left, right);
			if (pivot_index == k)
				break;
			if (pivot_index < k)
				left = pivot_index + 1;
			if (pivot_index > k)
				right = pivot_index - 1;
		}
		return nums[pivot_index];
	}

	int quick_select(vector<int>& nums, int left, int right) {
		// Pick a random pivot
		std::uniform_int_distribution<int> dis(left, right);
		int random_pivot = dis(gen);
		std::swap(nums[random_pivot], nums[right]);
		int pivot = nums[right];
		int pivot_index = left;
		while (left < right) {
			if (nums[left] <= pivot) {
				std::swap(nums[left], nums[pivot_index]);
				pivot_index++;
			}
			++left;
		}
		std::swap(nums[right], nums[pivot_index]);
		return pivot_index;
	}
};
