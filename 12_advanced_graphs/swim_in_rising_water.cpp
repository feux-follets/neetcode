class Solution {
	const vector<vector<int>> directions {
		{ 0,	1},
		{ 0, -1},
		 { 1,	 0},
		 {-1,  0}
	};

  public:
	int swimInWater(vector<vector<int>>& grid) {
		const int n = grid.size();

		if (n == 1)
			return grid[0][0];

		priority_queue<vector<int>, vector<vector<int>>, greater<>> min_heap;
		min_heap.emplace(vector {grid[0][0], 0, 0});
		vector visited(n, vector(n, false));
		visited[0][0] = true;

		int result = max(grid[0][0], grid[n - 1][n - 1]);
		while (!min_heap.empty()) {
			const vector<int> curr = min_heap.top();
			min_heap.pop();

			result = max(result, curr[0]);

			for (int i = 0; i < 4; ++i) {
				const int x = curr[1] + directions[i][0];
				const int y = curr[2] + directions[i][1];

				if (x < 0 || y < 0 || x >= n || y >= n || visited[x][y])
					continue;

				if (x == n - 1 && y == n - 1)
					return result;

				min_heap.emplace(vector {grid[x][y], x, y});
				visited[x][y] = true;
			}
		}

		return -1;
	}
};
