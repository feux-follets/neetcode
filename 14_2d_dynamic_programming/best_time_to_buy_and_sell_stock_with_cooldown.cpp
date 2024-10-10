class Solution {
  public:
	int maxProfit(vector<int>& prices) {
		const int n = prices.size();
		int buy = 0, sell = 0, cd = 0;
		buy = -prices[0];

		for (const int price : prices) {
			const int prev_sell = sell;
			// No action or sell
			sell = max(sell, buy + price);
			// No action or buy after cooldown
			buy = max(buy, cd - price);
			// No action or forced to cooldown
			cd = max(cd, prev_sell);
		}
		return max(cd, sell);
	}
};
