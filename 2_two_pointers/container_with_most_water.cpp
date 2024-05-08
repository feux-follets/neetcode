class Solution {
  public:
	int maxArea(vector<int>& height) {
		int max_area {};

		int left {}, right = height.size() - 1;
		while (left < right) {
			int h = min(height[left], height[right]);
			max_area = max(max_area, (right - left) * h);
			while (height[left] <= h && left < right)
				++left;
			while (height[right] <= h && left < right)
				--right;
		}

		return max_area;
	}
};
