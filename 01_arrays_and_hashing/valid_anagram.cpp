class Solution {
  public:
	bool isAnagram(string s, string t) {
		array<int, 26> a {};
		for (const char c : s)
			a.at(c - 'a')++;
		for (const char c : t)
			a.at(c - 'a')--;
		for (auto i : a)
			if (i)
				return false;

		return true;
	}
};
