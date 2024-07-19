class Solution {
  public:
	ListNode* reverseList(ListNode* head) {
		ListNode* prev = nullptr;
		ListNode* next = nullptr;
		while (head) {
			next = head->next;
			head->next = prev;
			prev = head;
			head = next;
		}
		return prev;
	}
};

class Solution {
  public:
	ListNode* reverseList(ListNode* head, ListNode* prev = nullptr) {
		return head ? reverseList(head->next, (head->next = prev, head)) : prev;
	}
};
