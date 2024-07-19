class Solution {
  public:
	string encode(vector<string>& strs) {
		string result;

		for (auto str : strs) {
			result += str.size();
			result += str;
		}
		return result;
	}

	vector<string> decode(string s) {
		if (s.empty())
			return {};
		vector<string> result;

		size_t i = 0;
		while (i < s.size()) {
			int count = s[i];
			string sub_str = s.substr(i + 1, count);
			i = i + 1 + count;
			result.push_back(sub_str);
		}

		return result;
	}
};
