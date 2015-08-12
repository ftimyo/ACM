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
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode h{0}, *p = &h, *q = head, *r = q->next;
		p->next = q;
		while (r != nullptr) {
			if (r->val != q->val) {
				p = q; q = r; r = q->next; continue;
			}
			while (r && r->val == q->val) r = r->next;
			while (q != r) {auto d = q; q = q->next; delete d;}
			p->next = q;
			if (q) r = q->next;
		}
		return h.next;
	}
};
