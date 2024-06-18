class Solution {
  public:
	int lastStoneWeight(vector<int>& stones) {
		priority_queue<int> pq(stones.begin(), stones.end());
		while (pq.size() > 1) {
			int stone_1 = pq.top();
			pq.pop();
			int stone_2 = pq.top();
			pq.pop();

			int new_stone = std::abs(stone_1 - stone_2);
			if (new_stone)
				pq.push(new_stone);
		}

		return pq.empty() ? 0 : pq.top();
	}
};
