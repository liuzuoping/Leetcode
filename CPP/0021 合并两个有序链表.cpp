class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* p = l1;
		ListNode* q = l2;
		ListNode* result = new ListNode(0);
		ListNode* r = result;
		while (p&&q) {
			if (q->val>p->val) {
				r->next = p;
				r = r->next;
				p = p->next;
			}
			else {
				r->next = q;
				r = r->next;
				q = q->next;
			}
		}
		if (q)
			r->next = q;
		if (p)
			r->next = p;
		return result->next;
	}
};