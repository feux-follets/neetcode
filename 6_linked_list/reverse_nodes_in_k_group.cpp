class Solution {
  public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		// Check if need reverse
		ListNode* iter = head;
		for (int i = 0; i < k; ++i) {
			if (iter == nullptr)
				return head;
			iter = iter->next;
		}

		// Reverse
		ListNode* curr = head;
		ListNode* prev = nullptr;
		ListNode* next = nullptr;
		for (int i = 0; i < k; ++i) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head->next = reverseKGroup(curr, k);
		return prev;
	}
};

class Solution {
  public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head || !head->next || k == 1)
			return head;

		// dummy->next points to the new head after reverse
		ListNode* dummy = new ListNode(-1, head);
		ListNode* before = dummy; // Before current group head
		ListNode* after = head;	  // Current group head

		ListNode* prev = nullptr;
		ListNode* curr = nullptr;
		ListNode* next = nullptr;
		while (true) {
			// Check if need reverse
			ListNode* cursor = after;
			for (int i = 0; i < k; ++i) {
				if (cursor == nullptr) {
					ListNode* result = dummy->next;
					delete dummy;
					return result;
				}
				cursor = cursor->next;
			}

			curr = after;  // Current head
			prev = before; // Before current head
			for (int i = 0; i < k; ++i) {
				next = curr->next;
				curr->next = prev;
				prev = curr;
				curr = next;
			}
			after->next = curr;	 // Point old group head->next to new group head
			before->next = prev; // Point dummy->next to old group tail (head after reverse)
			before = after;		 // Set dummy to before new group head
			after = curr;		 // Set new group head
		}
	}
};
