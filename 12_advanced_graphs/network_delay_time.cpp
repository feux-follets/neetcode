class Solution {
  public:
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {

		vector<vector<pair<int, int>>> edges(n + 1);

		for (const auto& time : times) {
			edges[time[0]].emplace_back(time[1], time[2]);
		}

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap;
		vector<int> signal_time(n + 1, INT_MAX);
		signal_time[k] = 0;
		min_heap.emplace(0, k);

		while (!min_heap.empty()) {
			const int weight = min_heap.top().first;
			const int node = min_heap.top().second;
			min_heap.pop();

			if (weight > signal_time[node])
				continue;

			for (const auto& p : edges[node]) {
				if (signal_time[p.first] > p.second + weight) {
					signal_time[p.first] = p.second + weight;
					min_heap.emplace(signal_time[p.first], p.first);
				}
			}
		}
		int result = -1;
		for (int i = 1; i < signal_time.size(); ++i) {
			result = max(result, signal_time[i]);
		}

		return result == INT_MAX ? -1 : result;
	}
};
