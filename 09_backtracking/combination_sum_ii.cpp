class Solution {
  public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>> result;
		vector<int> curr;
		std::sort(candidates.begin(), candidates.end());
		backtrack(candidates, result, curr, target, 0);
		return result;
	}

	void backtrack(const vector<int>& candidates, vector<vector<int>>& result, vector<int>& curr, int target,
				   int start) {
		if (target == 0) {
			result.push_back(curr);
			return;
		}
		for (int i = start; i < candidates.size(); ++i) {
			if (candidates[i] > target)
				break;
			if (i > start && candidates[i] == candidates[i - 1])
				continue;
			curr.push_back(candidates[i]);
			backtrack(candidates, result, curr, target - candidates[i], i + 1);
			curr.pop_back();
		}
	}
};
