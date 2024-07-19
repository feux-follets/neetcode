class TimeMap {
  public:
	TimeMap() {}

	void set(string key, string value, int timestamp) { m[key].emplace_back(timestamp, value); }

	string get(string key, int timestamp) {
		if (!m.contains(key))
			return "";

		int beg = 0;
		int end = m[key].size() - 1;
		if (m[key][beg].first > timestamp)
			return "";
		if (m[key][end].first < timestamp)
			return m[key][end].second;

		while (beg <= end) {
			const int mid = beg + (end - beg) / 2;
			if (m[key][mid].first == timestamp)
				return m[key][mid].second;
			if (m[key][mid].first < timestamp) {
				beg = mid + 1;
			} else
				end = mid - 1;
		}
		// end < 0 means all key are > timestamp
		return end >= 0 ? m[key][end].second : "";
	}

	std::unordered_map<string, vector<pair<int, string>>> m;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
