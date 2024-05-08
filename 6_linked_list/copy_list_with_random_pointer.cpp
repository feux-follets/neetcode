class Solution {
  public:
	Node* copyRandomList(Node* head) {
		if (head == nullptr)
			return nullptr;
		Node* iter = head;
		while (iter) {
			Node* new_node = new Node(iter->val);
			new_node->next = iter->next;
			iter->next = new_node;
			iter = new_node->next;
		}
		iter = head;
		while (iter) {
			if (iter->random)
				iter->next->random = iter->random->next;
			iter = iter->next->next;
		}
		Node* new_head = head->next;
		Node* new_iter = new_head;
		iter = head;
		while (iter) {
			iter->next = new_iter->next;
			iter = iter->next;
			new_iter->next = iter ? iter->next : iter;
			new_iter = new_iter->next;
		}

		return new_head;
	}
};

class Solution {
  public:
	Node* copyRandomList(Node* head) {
		if (head == nullptr)
			return nullptrCopy List with Random Pointer;
		unordered_map<Node*, Node*> m;

		Node* iter = head;
		while (iter) {
			Node* new_node = new Node(iter->val);
			m.emplace(iter, new_node);
			iter = iter->next;
		}
		iter = head;
		while (iter) {
			m[iter]->next = m[iter->next];
			m[iter]->random = m[iter->random];
			iter = iter->next;
		}
		return m[head];
	}
};
