#include <cstring>
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
struct ListNode* partition(struct ListNode* head, int x) {
	struct ListNode l, r, *s = &l, *t = &r;
	l.next = r.next = NULL;
	for (; head != NULL; head = head->next) {
		if (head->val < x) {
			s->next = head;
			s = head;
		} else {
			t->next = head;
			t = head;
		}
	}
	s->next = r.next;
	t->next = NULL;
	return l.next;
}
