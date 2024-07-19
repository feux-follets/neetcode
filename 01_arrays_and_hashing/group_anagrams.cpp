using Anagram = array<int, 26>;

template <>
struct std::hash<Anagram> {
	std::size_t operator()(const Anagram& s) const noexcept {
		std::size_t h {};
		for (const auto p : s) {
			h ^= std::hash<int> {}(p) + 0x9e3779b9 + (h << 6) + (h >> 2);
		}
		return h;
	}
};

class Solution {
  public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<Anagram, vector<string>> m;
		for (const auto& s : strs) { // O(strs.size())
			Anagram a {};

			// Group anagrams
			for (const char c : s) // O(s.size())
				a[c - 'a']++;
			if (m.contains(a)) // O(1)
				m.at(a).emplace_back(s);
			else
				m.emplace(a, vector<string> {s});
		}

		vector<vector<string>> result;
		result.reserve(m.size());
		for (const auto& p : m) {
			result.emplace_back(p.second);
		}

		return result;
	}
};
