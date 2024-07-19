class MedianFinder {
  public:
	priority_queue<int> lower;
	priority_queue<int, vector<int>, greater<int>> higher;

	MedianFinder() {}

	void addNum(int num) {
		if (lower.empty()) {
			lower.push(num);
			return;
		}
		if (lower.size() > higher.size()) {
			// Check num goes where
			if (num <= lower.top()) {
				lower.push(num);
				higher.push(lower.top());
				lower.pop();
			} else
				higher.push(num);
		} else {
			if (num >= higher.top()) {
				higher.push(num);
				lower.push(higher.top());
				higher.pop();
			} else
				lower.push(num);
		}
	}

	double findMedian() {
		if (lower.size() == higher.size())
			return (lower.top() + higher.top()) / 2.0;
		return lower.top();
	}
};
