class Solution {
  public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		for (int i = 0, j = numbers.size() - 1; i < j;) {
			int sum = numbers[i] + numbers[j];
			if (sum > target)
				--j;
			else if (sum < target)
				++i;
			else
				return {i + 1, j + 1};
		}
		return {};
	}
};
