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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode h(0); h.next = head;
		auto p = &h, q = &h;
		for (int i = 0; i < n; ++i) q = q->next;
		while (q->next) {q = q->next; p = p->next;}
		auto d = p->next;
		p->next = d->next;
		delete d;
		return h.next;
	}
};
