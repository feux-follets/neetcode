// Time: O(n x m) : Number of strings x Length of the shortest string
// Space: O(1)

class Solution {
  public:
	string longestCommonPrefix(vector<string>& strs) {
		for (int i = 0; i < strs[0].length(); i++) {
			for (const string& s : strs) {
				if (i > s.length() || strs[0][i] != s[i]) {
					return strs[0].substr(0, i);
				}
			}
		}
		return strs[0];
	}
};
