class Solution {
  public:
	string longestPalindrome(string s) {
		int max_length = 1;
		int index = 0;

		auto expand_mid = [&](int i, int j) {
			while (i >= 0 && j < s.size() && s[i] == s[j]) {
				i--;
				j++;
			}
			if (j - i - 1 > max_length) {
				max_length = j - i - 1;
				index = i + 1;
			}
		};

		for (int i = 0; i < s.size(); ++i) {
			// Odd
			expand_mid(i, i);
			// Even
			expand_mid(i, i + 1);
		}
		return s.substr(index, max_length);
	}
};
