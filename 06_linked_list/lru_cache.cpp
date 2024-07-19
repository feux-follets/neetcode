class LRUCache {
	class Node {
	  public:
		Node* prev = nullptr;
		Node* next = nullptr;
		int key {};
		int value {};

		explicit Node(int key, int value) : key(key), value(value) {}
	};

  public:
	int capacity;
	std::map<int, Node*> cache;
	Node* head = nullptr;
	Node* tail = nullptr;

	LRUCache(int capacity) : capacity(capacity) {}

	int get(int key) {
		if (!cache.contains(key))
			return -1;
		move_to_front(cache[key]);
		return head->value;
	}

	void put(int key, int value) {
		if (cache.contains(key)) {
			cache[key]->value = value;
			move_to_front(cache[key]);
		} else if (cache.size() == capacity) {
			cache.erase(tail->key);
			move_to_front(tail);
			cache[key] = head;
			cache[key]->key = key;
			cache[key]->value = value;
		} else {
			cache[key] = new Node(key, value);
			move_to_front(cache[key]);
		}
	}

	void move_to_front(Node* target) {
		Node* prev = target->prev;
		Node* next = target->next;
		if (target == head) {
			return;
		}
		if (target == tail) {
			tail = prev;
			prev->next = next;
		} else if (prev && next) {
			prev->next = next;
			next->prev = prev;
		}

		target->prev = nullptr;
		target->next = head;
		if (head)
			head->prev = target;
		if (!tail)
			tail = target;
		head = target;
	}
};

class LRUCache {
	int capacity {};
	std::list<std::pair<int, int>> l;
	std::array<decltype(l)::iterator, 10001> cache;

  public:
	LRUCache(int capacity) : capacity(capacity) { cache.fill(l.end()); }

	int get(int key) {
		if (cache[key] == l.end())
			return -1;
		l.splice(l.begin(), l, cache[key]);
		return l.begin()->second;
	}

	void put(int key, int value) {
		if (cache[key] != l.end()) {
			l.splice(l.begin(), l, cache[key]);
			cache[key]->second = value;
			return;
		}
		if (capacity == l.size()) {
			auto last_key = l.back().first;
			l.pop_back();
			cache[last_key] = l.end();
		}
		l.emplace_front(key, value);
		cache[key] = l.begin();
	}
};
