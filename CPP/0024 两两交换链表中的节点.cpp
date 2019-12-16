class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* pre = dummy;
		while (pre->next&&pre->next->next) {
			ListNode* cur = pre->next;
			ListNode* post = pre->next->next;
			pre->next = post;
			cur->next = post->next;
			post->next = cur;
			pre = pre->next->next;
		}
		return dummy->next;
	}
};