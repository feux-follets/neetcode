class Solution {
  public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1)
			return 0;
		int answer {};

		int start = 0;
		for (int i = 1; i < prices.size(); ++i) {
			int profit = prices.at(i) - prices.at(start);
			if (profit > answer) {
				answer = profit;
			}
			if (prices[i] < prices[start])
				start = i;
		}
		return answer;
	}
};
