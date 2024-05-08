class Solution {
  public:
	vector<int> dailyTemperatures(vector<int>& temperatures) {
		stack<pair<int, int>> st;
		vector<int> result(temperatures.size(), 0);
		for (int i = temperatures.size() - 1; i >= 0; --i) {
			while (!st.empty()) {
				if (st.top().first > temperatures[i]) {
					result[i] = st.top().second - i;
					break;
				} else {
					st.pop();
				}
			}
			st.emplace(temperatures[i], i);
		}
		return result;
	}
};
