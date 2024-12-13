class Solution {
  public:
	bool isAnagram(string s, string t) {
		vector result(26, 0);
		if (s.size() != t.size()) {
			return false;
		}
		for (size_t i = 0; i < s.size(); ++i) {
			result[s[i] - 'a']++;
			result[t[i] - 'a']--;
		}

		return ranges::all_of(result, [](int count) { return count == 0; });
	}
};
