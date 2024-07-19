class Solution {
  public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> dq;
		vector<int> result;
		int i = 0, j = 0;
		while (j < nums.size()) {
			// Remove all element smaller nums[j]
			while (!dq.empty() && nums[dq.back()] < nums[j])
				dq.pop_back();
			dq.push_back(j);
			// Remove the front element as the windows does not contain it
			if (i > dq.front()) {
				dq.pop_front();
			}
			if (j + 1 >= k) {
				result.push_back(nums[dq.front()]);
				++i;
			}
			++j;
		}
		return result;
	}
};
