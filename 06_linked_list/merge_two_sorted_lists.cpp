class Solution {
  public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if (!list1 && !list2)
			return nullptr;
		if (!list1)
			return list2;
		if (!list2)
			return list1;

		ListNode* left = list1;
		ListNode* right = list2;
		ListNode* head = left->val < right->val ? (left = left->next, list1) : (right = right->next, list2);
		ListNode* curr = head;
		while (left && right) {
			if (left->val < right->val) {
				curr->next = left;
				left = left->next;
			} else {
				curr->next = right;
				right = right->next;
			}
			curr = curr->next;
		}
		curr->next = left ? left : right;
		return head;
	}
};

class Solution {
  public:
	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if (!list1 || (list2 && list1->val > list2->val))
			swap(list1, list2);
		if (list1)
			list1->next = mergeTwoLists(list1->next, list2);
		return list1;
	}
};
