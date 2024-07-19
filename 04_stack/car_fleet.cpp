class Solution {
  public:
	int carFleet(int target, vector<int>& position, vector<int>& speed) {
		int result = 0;
		double slowest_time = numeric_limits<double>::lowest();
		vector<pair<int, int>> v;
		v.reserve(position.size());

		for (int i = 0; i < position.size(); ++i) {
			v.emplace_back(position[i], speed[i]);
		}
		ranges::sort(v, [](auto& left, auto& right) { return left.first > right.first; });
		for (const auto& p : v) {
			// Calculate time at target
			// Slower time means it will not collide with car ahead
			if (const double arrival_time = (target - static_cast<double>(p.first)) / p.second;
				arrival_time > slowest_time) {
				result++;
				slowest_time = arrival_time;
			}
		}
		return result;
	}
}
