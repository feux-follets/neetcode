class Solution {
  public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		unordered_map<int, vector<int>> preq_map;
		for (int i = 0; i < numCourses; ++i) {
			preq_map.emplace(i, std::vector<int>());
		}
		for (const auto& p : prerequisites) {
			preq_map[p[0]].push_back(p[1]);
		}
		unordered_set<int> visited;
		for (int i = 0; i < numCourses; ++i) {
			if (!dfs(i, visited, preq_map))
				return false;
		}
		return true;
	}

	bool dfs(const int course, unordered_set<int>& visited, unordered_map<int, vector<int>>& preq_map) {
		if (visited.contains(course))
			return false;
		if (preq_map[course].empty()) {
			return true;
		}
		visited.emplace(course);
		auto& prerequisites = preq_map[course];
		for (auto iter = prerequisites.begin(); iter != prerequisites.end();) {
			if (!dfs(*iter, visited, preq_map))
				return false;
			iter = prerequisites.erase(iter);
		}
		visited.erase(course);
		return true;
	}
};
