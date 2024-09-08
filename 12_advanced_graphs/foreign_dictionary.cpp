class Solution {
  public:
	string foreignDictionary(vector<string>& words) {
		unordered_map<char, bool> visited;
		unordered_map<char, unordered_set<char>> adj_list;
		for (const auto& word : words) {
			for (const char c : word) {
				if (adj_list.find(c) == adj_list.end())
					adj_list[c] = unordered_set<char>();
			}
		}

		for (int i = 0; i < words.size() - 1; ++i) {
			const string word_1 = words[i];
			const string word_2 = words[i + 1];
			const int min_len = min(word_1.size(), word_2.size());

			if (word_1.size() > word_2.size() && word_1.substr(0, min_len) == word_2.substr(0, min_len))
				return "";

			for (int j = 0; j < min_len; ++j) {
				if (word_1[j] != word_2[j]) {
					adj_list[word_1[j]].insert(word_2[j]);
					break;
				}
			}
		}

		string result;
		function<bool(char)> dfs = [&](const char c) {
			if (visited.find(c) != visited.end())
				return visited[c];

			visited[c] = true;
			if (adj_list.find(c) != adj_list.end()) {
				for (char neighbor : adj_list[c]) {
					if (dfs(neighbor))
						return true;
				}
			}
			visited[c] = false;
			result.push_back(c);
			return false;
		};

		for (const auto& p : adj_list) {
			if (dfs(p.first))
				return "";
		}

		reverse(result.begin(), result.end());
		return result;
	}
};
