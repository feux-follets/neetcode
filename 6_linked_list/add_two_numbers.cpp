class Solution {
  public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* dummy = new ListNode(0);
		ListNode* tail = dummy;
		int carry = 0;

		while (l1 || l2 || carry) {
			int digit_1 = l1 ? l1->val : 0;
			int digit_2 = l2 ? l2->val : 0;
			int sum = digit_1 + digit_2 + carry;
			carry = sum / 10;
			sum = sum % 10;

			ListNode* new_node = new ListNode(sum);
			tail->next = new_node;
			tail = tail->next;

			if (l1)
				l1 = l1->next;
			if (l2)
				l2 = l2->next;
		}
		tail = dummy->next;
		delete dummy;
		return tail;
	}
};
