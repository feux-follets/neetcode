class Solution {
  public:
	string minWindow(string s, string t) {
		if (t.length() > s.length())
			return "";
		unordered_map<char, int> m;
		for (const char c : t)
			m[c]++;

		int counter = t.size();
		int i = 0, j = 0, min_length = INT_MAX, head = 0;

		while (j < s.length()) {
			if (m[s[j]] > 0) {
				counter--;
			}
			// Save extra char in t as well
			m[s[j]]--;
			++j;

			while (counter == 0) {
				if (j - i < min_length) {
					min_length = j - i;
					head = i;
				}
				// s[i] must be in t
				m[s[i]]++;
				// no more extra s[i] in t
				if (m[s[i]] > 0) {
					counter++;
				}
				i++;
			}
		}
		return min_length == INT_MAX ? "" : s.substr(head, min_length);
	}
};
