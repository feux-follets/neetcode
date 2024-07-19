class Solution {
  public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> m; // num : frequency
		for (const int n : nums)   // O(N)
			m[n]++;				   // O(1)

		vector<vector<int>> buckets(nums.size() + 1); // frequency : [num]
		for (const auto p : m)						  // O(N)
			buckets[p.second].push_back(p.first);	  // O(1)

		vector<int> result;
		for (auto iter = buckets.rbegin(); iter != buckets.rend(); ++iter) {
			for (const int i : *iter) {
				result.emplace_back(i);
				if ((--k) == 0)
					return result;
			}
		}
		return result;
	}
};
