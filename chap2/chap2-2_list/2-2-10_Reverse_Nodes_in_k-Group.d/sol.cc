#include <cstring>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *	 int val;
 *	 ListNode *next;
 *	 ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head || !head->next || k < 2) return head;
		ListNode h{0}; h.next = head;
		for (auto p = &h, q = p->next; q != nullptr; q = p->next) {
			for (int i = 1; i < k && q; ++i) q = q->next;
			if (!q) break;
			auto r = q->next, e = p->next;
			q = e;
			while (q != r) {
				auto t = q->next;
				q->next = p->next;
				p->next = q;
				q = t;
			}
			e->next = r; p = e;
		}
		return h.next;
	}
};
