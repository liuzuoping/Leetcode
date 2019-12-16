class Solution {
public:
	ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
		if (!l1 && !l2) {
			return nullptr;
		}if (!l1) {
			return l2;
		}if (!l2) {
			return l1;
		}
		ListNode* head = new ListNode(-1);
		ListNode* point = head;
		while (l1&&l2) {
			if (l1->val <= l2->val) {
				point->next = l1;
				l1 = l1->next;
			}
			else {
				point->next = l2;
				l2 = l2->next;
			}
			point = point->next;
		}
		if (l1) {
			point->next = l1;
		}
		if (l2) {
			point->next = l2;
		}
		return head->next;
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int cnt = lists.size();
		int k = 1;
		while (k<cnt) {
			for (int i = 0; i<cnt - k; i += 2 * k) {
				lists[i] = merge2Lists(lists[i], lists[i + k]);
			}
			k *= 2;
		}
		if (cnt>0) {
			return lists[0];
		}
		else {
			return nullptr;
		}
	}
};