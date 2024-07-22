class Solution {
  public:
	Node* cloneGraph(Node* node) {
		if (node == nullptr)
			return nullptr;
		std::unordered_map<Node*, Node*> m;
		m[node] = new Node(node->val, node->neighbors);
		std::queue<Node*> q;
		q.push(node);
		while (!q.empty()) {
			Node* curr = q.front();
			q.pop();

			for (int i = 0; i < curr->neighbors.size(); ++i) {
				Node* neighbor = curr->neighbors[i];
				if (!m.contains(neighbor)) {
					m.emplace(neighbor, new Node(neighbor->val, neighbor->neighbors));
					q.push(neighbor);
				}
				m[curr]->neighbors[i] = m[neighbor];
			}
		}
		return m[node];
	}
};
