#include <string.h>
#include <stdlib.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *	 int val;
 *	 struct ListNode *next;
 * };
 */
struct ListNode {
	int val;
	struct ListNode *next;
};
struct ListNode* deleteDuplicates(struct ListNode* head) {
	if (!head || !head->next) return head;
	struct ListNode h, *p = &h, *q = head, *r = q->next;
	p->next = q;
	while (r != NULL) {
		if (r->val != q->val) {p = q; q = r; r = q->next; continue;}
		while (r && r->val == q->val) r = r->next;
		while (q != r) {struct ListNode *d = q; q = q->next; free(d);}
		p->next = q;
		if (q) r = q->next;
	}
	return h.next;
}
