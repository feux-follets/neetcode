class Solution {
  public:
	int characterReplacement(string s, int k) {
		vector<int> count(26);
		int max_count = 0;

		int i = 0, j = 0;
		int result = 0;

		while (j < s.size()) {
			count[s[j] - 'A']++;
			max_count = max(max_count, count[s[j] - 'A']);
			if (j - i + 1 - max_count > k) {
				count[s[i] - 'A']--;
				++i;
			} else
				result = max(result, j - i + 1);
			++j;
		}
		return result;
	}
};
