// Time: O(M+N)
// Space: O(1)

class Solution {
  public:
	bool isAnagram(string s, string t) {
		const int M = s.length();
		const int N = t.length();
		if (M != N)
			return false;

		vector<int> count(26, 0);
		for (int i = 0; i < M; ++i) {
			count[s[i] - 'a']++;
			count[t[i] - 'a']--;
		}
		for (const int i : count) {
			if (i != 0)
				return false;
		}
		return true;
	}
};
