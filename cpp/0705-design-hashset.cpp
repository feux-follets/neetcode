// Time: O(1)
// Space: O(31251)

class MyHashSet {
  public:
	MyHashSet() {}

	void add(int key) { mask[key / 32] |= getMask(key); }

	void remove(int key) { mask[key / 32] &= ~getMask(key); }

	bool contains(int key) { return mask[key / 32] & getMask(key); }

  private:
	int mask[31251] {};

	int getMask(int key) { return 1 << key % 32; }
};
