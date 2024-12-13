// Time: O(1)
// Space: O(1000001)

class MyHashMap {
  public:
	MyHashMap() { memset(map, ~0, sizeof(map)); }

	void put(int key, int value) { map[key] = value; }

	int get(int key) { return map[key]; }

	void remove(int key) { map[key] = ~0; }

  private:
	int map[1000001];
};
