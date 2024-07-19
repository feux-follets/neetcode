class Solution {
  public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> s;
		for (const int i : nums) { // O(N)
			if (s.contains(i))	   // O(1) Average
				return true;
			s.emplace(i); // O(1) Average
		}

		return false;
	}
};
