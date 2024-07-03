class Solution {
	vector<string> m = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

  public:
	vector<string> letterCombinations(string digits) {
		if (digits.empty())
			return {};
		vector<string> result;
		string curr;
		dfs(digits, result, 0, curr);
		return result;
	}

	void dfs(const string& digits, vector<string>& result, const int index, string& curr) {
		if (index == digits.size()) {
			result.push_back(curr);
			return;
		}
		const string str = m[digits[index] - '2'];
		for (const char c : str) {
			curr.push_back(c);
			dfs(digits, result, index + 1, curr);
			curr.pop_back();
		}
	}
};
