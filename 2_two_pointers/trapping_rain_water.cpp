class Solution {
  public:
	int trap(vector<int>& height) {
		int left {};
		int right = height.size() - 1;

		int max_left = height[left];
		int max_right = height[right];

		int result {};
		while (left < right) {
			if (max_left <= max_right) {
				++left;
				max_left = max(max_left, height[left]);
				result += max_left - height[left];
			} else {
				--right;
				max_right = max(max_right, height[right]);
				result += max_right - height[right];
			}
		}
		return result;
	}
};
