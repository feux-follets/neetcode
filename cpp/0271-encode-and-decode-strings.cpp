// Time: O(n) Sum of lengths of all strs
// Space: O(1)

class Solution {
  public:
	string encode(vector<string>& strs) {
		string s;
		for (const auto& str : strs) {
			s += to_string(str.size()) + "#" + str;
		}
		return s;
	}

	vector<string> decode(string s) {
		vector<string> result;

		int i = 0;
		while (i < s.size()) {
			int j = i;
			while (s[j] != '#')
				++j;
			int length = stoi(s.substr(i, j - i));
			i = j + 1;
			j = i + length;
			result.push_back(s.substr(i, length));
			i = j;
		}

		return result;
	}
};
