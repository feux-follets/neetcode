class Solution {
  public:
	void reorderList(ListNode* head) {
		if (head->next == nullptr || head->next->next == nullptr)
			return;
		ListNode* prev = nullptr;
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast && fast->next) {
			prev = slow;
			fast = fast->next->next;
			slow = slow->next;
		}
		prev->next = nullptr;
		ListNode* l1 = head;
		ListNode* l2 = reverse(slow);

		while (l1) {
			ListNode* p1 = l1->next;
			ListNode* p2 = l2->next;
			l1->next = l2;
			if (p1 == nullptr)
				break;
			l2->next = p1;

			l1 = p1;
			l2 = p2;
		}
	}

	ListNode* reverse(ListNode* head, ListNode* prev = nullptr) {
		return head ? reverse(head->next, (head->next = prev, head)) : prev;
	}
};
