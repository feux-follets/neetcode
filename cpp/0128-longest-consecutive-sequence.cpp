// Time: O(n)
// Space: O(n)

class Solution {
  public:
	int longestConsecutive(vector<int>& nums) {
		unordered_map<int, int> m;
		int result = 0;
		for (const int i : nums) {
			if (!m[i]) {
				m[i] = m[i - 1] + m[i + 1] + 1;
				m[i - m[i - 1]] = m[i];
				m[i + m[i + 1]] = m[i];
				result = max(result, m[i]);
			}
		}

		return result;
	}
};
