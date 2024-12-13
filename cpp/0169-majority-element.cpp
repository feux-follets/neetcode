class Solution {
  public:
	int majorityElement(vector<int>& nums) {
		int count = 0;
		int result = 0;
		for (const int num : nums) {
			if (count == 0) {
				result = num;
			}
			num == result ? ++count : --count;
		}
		return result;
	}
};
