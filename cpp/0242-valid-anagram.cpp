// Time: O(N)
// Space: O(1)

class Solution {
  public:
	bool isAnagram(string s, string t) {
		const int M = s.size();
		const int N = t.size();
		if (M != N)
			return false;

		vector<int> count(26, 0);
		for (int i = 0; i < M; i++) {
			count[s[i] - 'a']++;
			count[t[i] - 'a']--;
		}

		for (int i = 0; i < 26; i++) {
			if (count[i] != 0)
				return false;
		}
		return true;
	}
};
