class Solution {
  public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		auto n = lists.size();
		if (n == 0)
			return nullptr;

		while (n > 1) {
			for (int i = 0; i < n / 2; ++i) {
				lists[i] = mergeTwoLists(lists[i], lists[n - 1 - i]);
			}
			n = (n + 1) / 2;
		}
		return lists.front();
	}

	ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if (!list1 || (list2 && list1->val > list2->val))
			swap(list1, list2);
		if (list1)
			list1->next = mergeTwoLists(list1->next, list2);
		return list1;
	}
};
