class Solution {
  public:
	int longestConsecutive(vector<int>& nums) {
		std::unordered_set<int> s(nums.begin(), nums.end());
		int max {};
		for (const int i : s) {
			if (s.find(i - 1) == s.end()) {
				int count {1}, curr {i};
				while (s.find(++curr) != s.end())
					++count;
				max = std::max(count, max);
			}
		}
		return max;
	}
};
