class Solution {
  public:
	int countSubstrings(string s) {
		int result = 0;

		auto expand_mid = [&](int i, int j) {
			while (i >= 0 && j < s.size() && s[i] == s[j]) {
				result++;
				i--;
				j++;
			}
		};

		for (int i = 0; i < s.size(); ++i) {
			expand_mid(i, i);
			expand_mid(i, i + 1);
		}
		return result;
	}
};
