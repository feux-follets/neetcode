class Solution {
  public:
	int countComponents(int n, vector<vector<int>>& edges) {
		vector<int> parent(n);
		vector<int> rank(n, 1);
		for (int i = 0; i < n; ++i) {
			parent[i] = i;
		}

		int result = n;
		for (const auto& edge : edges) {
			result -= do_union(parent, rank, edge[0], edge[1]);
		}

		return result;
	}

	int find_parent(vector<int>& parent, const int node) {
		int result = node;
		while (parent[result] != result) {
			parent[result] = parent[parent[result]];
			result = parent[result];
		}
		return result;
	}

	int do_union(vector<int>& parent, vector<int>& rank, const int node_1, const int node_2) {
		int parent_1 = find_parent(parent, node_1);
		int parent_2 = find_parent(parent, node_2);
		if (parent_1 == parent_2)
			return 0;

		if (rank[parent_1] > rank[parent_2]) {
			parent[parent_2] = parent_1;
			rank[parent_1] += rank[parent_2];
		} else {
			parent[parent_1] = parent_2;
			rank[parent_2] += rank[parent_1];
		}
		return 1;
	}
};
