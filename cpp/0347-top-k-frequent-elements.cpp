// Time: O(n)
// Space: O(n)

class Solution {
  public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> m;
		for (const int i : nums) {
			m[i]++;
		}
		vector<vector<int>> freq(nums.size() + 1);
		for (const auto& entry : m) {
			freq[entry.second].push_back(entry.first);
		}
		vector<int> result(k);
		for (int i = freq.size() - 1; i >= 0 && k; --i) {
			for (const int n : freq[i]) {
				result[--k] = n;
				if (k == 0)
					break;
			}
		}
		return result;
	}
};
