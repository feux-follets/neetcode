class Solution {
  public:
	int leastInterval(vector<char>& tasks, int n) {
		// ['A'->'B'->'C'] -> ['A','B','D'] ->['A','B']
		// (n+1)*(max frequency - 1) + count_of_max_frequency
		vector<int> frequency(26, 0);
		int max_frequency = 0;
		int count_max_frequency = 0;
		for (const char c : tasks) {
			frequency[c - 'A']++;
			int curr_count = frequency[c - 'A'];

			if (curr_count > max_frequency) {
				max_frequency = curr_count;
				count_max_frequency = 1;
			} else if (curr_count == max_frequency)
				++count_max_frequency;
		}

		std::size_t result = (n + 1) * (max_frequency - 1) + count_max_frequency;
		return std::max(tasks.size(), result);
	}
};

class Solution {
  public:
	int leastInterval(vector<char>& tasks, int n) {
		vector<int> task_count(26, 0);
		for (const char c : tasks) {
			task_count[c - 'A']++;
		}
		priority_queue<int> pq;
		for (int i = 0; i < task_count.size(); ++i) {
			if (task_count[i])
				pq.push(task_count[i]);
		}
		int result = 0;
		while (!pq.empty()) {
			int cycle = n + 1;
			vector<int> v;
			while (cycle) {
				if (v.empty() && pq.empty())
					break;
				if (pq.size()) {
					auto top = pq.top();
					pq.pop();
					top--;
					if (top)
						v.push_back(top);
				}
				++result;
				cycle--;
			}
			for (auto p : v)
				pq.push(p);
		}
		return result;
	}
};
