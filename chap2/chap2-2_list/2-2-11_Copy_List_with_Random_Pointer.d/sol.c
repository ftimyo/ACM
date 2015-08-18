#include <stdlib.h>
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *	 int label;
 *	 struct RandomListNode *next;
 *	 struct RandomListNode *random;
 * };
 */
struct RandomListNode {
	int label;
	struct RandomListNode *next;
	struct RandomListNode *random;
};
#define H struct RandomListNode
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
	if (!head) return head;
	for (H *p = head; p != NULL; p = p->next->next) {
		H *q = (H*)malloc(sizeof(*p));
		q->next = p->next; q->label = p->label;
		p->next = q;
	}
	for (H *p = head; p != NULL; p = p->next->next)
		if (p->random) p->next->random = p->random->next;
		else p->next->random = NULL;
	H h;
	for (H *p = head, *q = &h; p != NULL; p = p->next) {
		q->next = p->next;
		q = q->next;
		p->next = q->next;
	}
	return h.next;
}
