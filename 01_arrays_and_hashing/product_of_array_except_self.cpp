class Solution {
  public:
	vector<int> productExceptSelf(vector<int>& nums) {
		auto n = nums.size();

		vector<int> result(n, 1);

		// Left
		for (int i = 1; i < n; ++i) {
			result[i] = result[i - 1] * nums[i - 1];
		}
		// Right
		int right_product = nums[n - 1];
		for (int i = result.size() - 2; i >= 0; --i) {
			result[i] *= right_product;
			right_product *= nums[i];
		}
		return result;
	}
};

// 1,2,3,4
// 1,1,1,1
// 1,1,2,6

// 1,1,2,6
//     8,6
