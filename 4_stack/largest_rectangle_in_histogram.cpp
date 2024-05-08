class Solution {
  public:
	int largestRectangleArea(vector<int>& heights) {
		int result = 0;
		stack<pair<int, int>> s;
		for (int i = 0; i < heights.size(); ++i) {
			int index = i;
			while (!s.empty() && heights[i] < s.top().second) {
				index = s.top().first;
				const int height = s.top().second;
				result = max(result, (i - index) * height);
				s.pop();
			}
			if (!s.empty() && s.top().second == heights[i])
				continue;
			s.emplace(index, heights[i]);
		}

		while (!s.empty()) {
			int area = s.top().second * (heights.size() - s.top().first);
			result = max(result, area);
			s.pop();
		}

		return result;
	}
};

class Solution {
  public:
	int largestRectangleArea(vector<int>& heights) {
		int result = 0;
		const int n = heights.size();
		int less_from_left[n];
		int less_from_right[n];
		less_from_left[0] = -1;
		less_from_right[n - 1] = n;
		for (int i = 1; i < n; ++i) {
			int p = i - 1;
			while (p >= 0 && heights[p] >= heights[i]) {
				p = less_from_left[p];
			}
			less_from_left[i] = p;
		}
		for (int i = n - 2; i >= 0; --i) {
			int p = i + 1;
			while (p <= n - 1 && heights[p] >= heights[i]) {
				p = less_from_right[p];
			}
			less_from_right[i] = p;
		}
		for (int i = 0; i < n; ++i) {
			result = max(result, heights[i] * (less_from_right[i] - less_from_left[i] - 1));
		}

		return result;
	}
};
