class Solution {
  public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> word_dict(wordList.begin(), wordList.end());
		queue<string> todo;
		todo.push(beginWord);
		int result = 1;
		while (!todo.empty()) {
			const int count = todo.size();
			for (int i = 0; i < count; ++i) {
				string word = todo.front();
				todo.pop();
				if (word == endWord) {
					return result;
				}
				word_dict.erase(word);
				for (int j = 0; j < word.size(); ++j) {
					const char c = word[j];
					for (int k = 0; k < 26; ++k) {
						word[j] = 'a' + k;
						if (word_dict.contains(word)) {
							todo.push(word);
							word_dict.erase(word);
						}
					}
					word[j] = c;
				}
			}
			result++;
		}
		return 0;
	}
};
