// bfs
class Solution {
  public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
		unordered_map<int, vector<pair<int, int>>> adj_list;
		for (const auto& flight : flights) {
			adj_list[flight[0]].emplace_back(flight[1], flight[2]);
		}

		queue<pair<int, int>> q;
		q.emplace(src, 0);
		vector min_cost(n, INT_MAX);

		while (!q.empty() && k-- >= 0) {
			int size = q.size();
			while (size--) {
				auto [from, from_cost] = q.front();
				q.pop();

				for (auto& [to, to_cost] : adj_list[from]) {
					if (const int total_cost = from_cost + to_cost; total_cost < min_cost[to]) {
						min_cost[to] = total_cost;
						q.emplace(to, total_cost);
					}
				}
			}
		}

		return min_cost[dst] == INT_MAX ? -1 : min_cost[dst];
	}
};

// Bellman Ford
class Solution {
  public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
		vector prices(n, INT_MAX);
		prices[src] = 0;

		while (k-- >= 0) {
			// Use a copy to take k into consideration
			auto tmp = prices;
			for (const auto& flight : flights) {
				if (prices[flight[0]] == INT_MAX)
					continue;
				tmp[flight[1]] = min(tmp[flight[1]], prices[flight[0]] + flight[2]);
			}
			prices = tmp;
		}
		return prices[dst] == INT_MAX ? -1 : prices[dst];
	}
};
