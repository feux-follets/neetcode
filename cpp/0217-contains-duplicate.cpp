// Time: O(n)
// Space: O(n)

class Solution {
  public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> s;
		for (const int i : nums) {
			if (s.contains(i))
				return true;
			s.insert(i);
		}
		return false;
		// return unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
	}
};
