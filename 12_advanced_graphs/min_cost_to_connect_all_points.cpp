class Solution {
  public:
	int minCostConnectPoints(vector<vector<int>>& points) {
		const int n = points.size();
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
		pq.emplace(0, 0);
		unordered_set<int> visited;

		int result = 0;
		while (visited.size() < n) {
			auto top = pq.top();
			pq.pop();
			if (visited.contains(top.second))
				continue;

			visited.insert(top.second);
			result += top.first;

			for (int i = 0; i < n; ++i) {
				if (visited.contains(i))
					continue;
				const int distance =
					abs(points[i][0] - points[top.second][0]) + abs(points[i][1] - points[top.second][1]);
				pq.emplace(distance, i);
			}
		}

		return result;
	}
};
