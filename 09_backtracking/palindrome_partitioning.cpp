class Solution {
  public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		vector<string> curr;
		dfs(s, result, curr, 0);
		return result;
	}

	void dfs(const string& s, vector<vector<string>>& result, vector<string>& curr, const int start) {
		if (start == s.size()) {
			result.push_back(curr);
			return;
		}
		for (int i = start; i < s.size(); ++i) {
			string temp = s.substr(start, i - start + 1);
			if (is_palindrome(temp)) {
				curr.push_back(temp);
				dfs(s, result, curr, i + 1);
				curr.pop_back();
			}
		}
	}

	bool is_palindrome(const string& input) {
		int i = 0;
		int j = input.size() - 1;

		while (i <= j) {
			if (input[i] != input[j])
				return false;
			i++;
			j--;
		}
		return true;
	}
};
