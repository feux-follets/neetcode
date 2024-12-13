// Time: O(n)
// Space: O(1)

class Solution {
  public:
	vector<int> majorityElement(vector<int>& nums) {
		// Boyer-Moore Voting Algorithm
		unordered_map<int, int> count;
		for (const int num : nums) {
			count[num]++;
			if (count.size() > 2) {
				unordered_map<int, int> temp;
				for (const auto entry : count) {
					if (entry.second > 1)
						temp[entry.first] = entry.second - 1;
				}
				count = temp;
			}
		}
		vector<int> result;
		for (const auto entry : count) {
			int frequency = 0;
			for (const int num : nums) {
				if (entry.first == num) {
					frequency++;
				}
			}
			if (frequency > nums.size() / 3)
				result.push_back(entry.first);
		}
		return result;
	}
};
