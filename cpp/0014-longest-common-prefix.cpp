class Solution {
  public:
	string longestCommonPrefix(vector<string>& strs) {
		for (size_t i = 0; i < strs.front().size(); ++i) {
			for (const auto& str : strs) {
				if (i == str.length() || str[i] != strs.front()[i]) {
					return strs.front().substr(0, i);
				}
			}
		}
		return strs.front();
	}
};
