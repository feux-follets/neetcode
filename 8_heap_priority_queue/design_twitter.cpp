class Twitter {
  public:
	unordered_map<int, unordered_set<int>> relationship;
	vector<pair<int, int>> tweets;

	Twitter() {}

	void postTweet(int userId, int tweetId) { tweets.emplace_back(userId, tweetId); }

	vector<int> getNewsFeed(int userId) {
		vector<int> result;
		for (auto iter = tweets.rbegin(); iter != tweets.rend(); ++iter) {
			if (iter->first == userId || relationship[userId].contains(iter->first)) {
				result.push_back(iter->second);
				if (result.size() == 10) {
					break;
				}
			}
		}
		return result;
	}

	void follow(int followerId, int followeeId) { relationship[followerId].insert(followeeId); }

	void unfollow(int followerId, int followeeId) { relationship[followerId].erase(followeeId); }
};
