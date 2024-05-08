class Solution {
  public:
	int minEatingSpeed(vector<int>& piles, int h) {

		int low = 1;
		int high = 0;
		for (int i = 0; i < piles.size(); ++i) {
			high = max(high, piles[i]);
		}

		int result = high;

		while (low <= high) {
			int k = low + (high - low) / 2;
			long int hours {};
			for (const int i : piles) {
				hours += std::ceil(static_cast<double>(i) / k);
			}
			if (hours > h)
				low = k + 1;
			else {
				result = min(result, k);
				high = k - 1;
			}
		}

		return result;
	}
};
