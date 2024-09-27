class Solution {
  public:
	int minCostClimbingStairs(vector<int>& cost) {
		const int size = cost.size();
		int first = cost[0];
		int second = cost[1];
		for (int i = 2; i < size; ++i) {
			int temp = min(first, second) + cost[i];
			first = second;
			second = temp;
		}
		return min(first, second);
	}
};
