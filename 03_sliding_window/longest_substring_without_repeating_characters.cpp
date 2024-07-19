class Solution {
  public:
	int lengthOfLongestSubstring(string s) {
		vector<int> dict(256, -1);
		int max_length = 0;
		int n = s.size();

		int left = 0;
		for (int right = 0; right < n; ++right) {
			if (dict[s[right]] >= left)
				left = dict[s[right]] + 1;
			dict[s[right]] = right;
			max_length = max(max_length, right - left + 1);
		}

		return max_length;
	}
};
