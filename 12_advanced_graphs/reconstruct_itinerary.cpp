class Solution {
  public:
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		vector<string> result;
		unordered_map<string, multiset<string>> adj_list;
		for (const auto ticket : tickets) {
			adj_list[ticket[0]].insert(ticket[1]);
		}
		dfs(adj_list, "JFK", result);
		reverse(result.begin(), result.end());
		return result;
	}

	void dfs(unordered_map<string, multiset<string>>& adj_list, const string& airport, vector<string>& result) {
		while (!adj_list[airport].empty()) {
			string next = *adj_list[airport].begin();
			adj_list[airport].erase(adj_list[airport].begin());
			dfs(adj_list, next, result);
		}
		result.push_back(airport);
	}
};
