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
	void reorderList(ListNode* head) {
		if (!head || !head->next) return;
		auto p = head, q = p, r = q;
		while (q && q->next) {p = p->next; r = q; q = q->next->next;}
		r = q ? q : r->next;
		auto h = p;
		while (p != r) {auto t = p->next; p->next = r->next; r->next = p; p = t;}
		for (p = head; p != h;) {
			auto t1 = p->next, t2 = r->next;
			p->next = r; r->next = t1;
			p = t1; r = t2;
		}
		h->next = nullptr;
	}
};
