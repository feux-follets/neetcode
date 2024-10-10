class Solution {
  public:
	int minDistance(string word1, string word2) {
		const int m = word1.size();
		const int n = word2.size();
		vector<int> curr(n + 1, 0);
		for (int j = 0; j <= n; ++j)
			curr[j] = j;
		int prev = 0;
		for (int i = 1; i <= m; ++i) {
			// Diagonal
			prev = curr[0];
			curr[0] = i;
			for (int j = 1; j <= n; ++j) {
				int temp = curr[j];
				if (word1[i - 1] == word2[j - 1]) {
					curr[j] = prev;
				} else {
					// curr[j] from last row, remove a char
					// curr[j-1] from left, add a char
					curr[j] = min(prev, min(curr[j], curr[j - 1])) + 1;
				}
				prev = temp;
			}
		}
		return curr[n];
	}
};
