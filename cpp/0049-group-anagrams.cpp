// Time: O(n * m) Number of strings x Average string length
// Space: O(n * m)

class Solution {
  public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> m;
		for (const string& str : strs) {
			vector<int> anagram(26, 0);
			for (const char c : str) {
				anagram[c - 'a']++;
			}
			string key;
			for (int i = 0; i < 26; ++i) {
				key += to_string(anagram[i]) + '#';
			}
			m[key].push_back(str);
		}

		vector<vector<string>> result(m.size());
		int i = 0;
		for (const auto& [anagram, strs] : m) {
			result[i++] = strs;
		}
		return result;
	}
};
