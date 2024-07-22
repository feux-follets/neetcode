class Solution {
  public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> result;
		vector<vector<int>> preq_map(numCourses);
		vector<bool> cycle(numCourses, false);
		vector<bool> visited(numCourses, false);
		for (const auto& p : prerequisites) {
			preq_map[p[0]].push_back(p[1]);
		}
		for (int i = 0; i < numCourses; ++i) {
			if (!dfs(i, preq_map, cycle, visited, result)) {
				return {};
			}
		}
		return result;
	}

	bool dfs(const int course, vector<vector<int>>& preq_map, vector<bool>& cycle, vector<bool>& visited,
			 vector<int>& result) {
		if (cycle[course])
			return false;
		if (visited[course]) {
			return true;
		}

		cycle[course] = true;
		auto& prerequisites = preq_map[course];
		for (const auto& p : prerequisites) {
			if (!dfs(p, preq_map, cycle, visited, result))
				return false;
		}
		prerequisites.clear();
		result.emplace_back(course);
		cycle[course] = false;
		visited[course] = true;
		return true;
	}
};
