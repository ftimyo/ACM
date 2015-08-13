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
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode h{0}, *p = &h, *q = p, *r = p, *t = p; h.next = head;
		while (t && t->next) {
			q = p->next; r = q->next; t = r->next;
			p->next = r; r->next = q; q->next = t;
			p = q;
		}
		return h.next;
	}
};
