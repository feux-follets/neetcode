class Solution {
  public:
	bool validTree(int n, vector<vector<int>>& edges) {
		vector<vector<int>> adj_list(n);
		vector<bool> visited(n, false);
		for (int i = 0; i < edges.size(); ++i) {
			adj_list[edges[i][0]].push_back(edges[i][1]);
			adj_list[edges[i][1]].push_back(edges[i][0]);
		}

		// Has cycle
		if (has_cycle(adj_list, visited, 0, -1))
			return false;
		// Has non visited node/disconnected
		for (int i = 0; i < n; ++i) {
			if (!visited[i])
				return false;
		}
		return true;
	}

	bool has_cycle(const vector<vector<int>>& adj_list, vector<bool>& visited, const int node, const int parent) {
		if (visited[node])
			return true;

		visited[node] = true;
		const auto& edges = adj_list[node];
		for (int i = 0; i < edges.size(); ++i) {
			// Skip checking same edge
			if (parent == edges[i])
				continue;
			if (has_cycle(adj_list, visited, edges[i], node))
				return true;
		}
		return false;
	}
};
