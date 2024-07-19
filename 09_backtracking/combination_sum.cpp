class Solution {
  public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		std::vector<int> curr;
		backtrack(candidates, target, 0, curr, result);
		return result;
	}

	void backtrack(const vector<int>& candidates, int target, int start, vector<int>& curr,
				   vector<vector<int>>& result) {
		for (int i = start; i < candidates.size(); ++i) {
			curr.push_back(candidates[i]);
			const int diff = target - candidates[i];
			if (diff == 0) {
				result.push_back(curr);
			} else if (diff > 0) {
				backtrack(candidates, diff, i, curr, result);
			}
			curr.pop_back();
		}
	}
};
