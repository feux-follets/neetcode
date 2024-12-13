// Time: O(N)
// Space: O(N)

class Solution {
  public:
	vector<int> getConcatenation(vector<int>& nums) {
		const int N = nums.size();
		vector<int> res(N * 2);
		for (int i = 0; i < N; i++) {
			res[i] = res[i + N] = nums[i];
		}
		return res;
	}
};
