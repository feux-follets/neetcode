class Solution {
  public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<std::array<int, 26>, vector<string>> m;

		for (auto& str : strs) {
			std::array<int, 26> anagram {};
			for (const auto c : str) {
				anagram[c - 'a']++;
			}
			m[anagram].push_back(move(str));
		}

		vector<vector<string>> result;
		for (auto& [key, value] : m) {
			result.push_back(move(value));
		}
		return result;
	}
};
