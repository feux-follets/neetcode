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
