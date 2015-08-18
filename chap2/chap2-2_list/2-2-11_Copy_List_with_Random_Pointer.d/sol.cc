#include <cstring>
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *	 int label;
 *	 RandomListNode *next, *random;
 *	 RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		using H = RandomListNode;
		if (!head) return head;
		for (auto p = head; p != nullptr; p = p->next->next)
			p->next = new H{*p};
		for (auto p = head; p != nullptr; p = p->next->next)
			if (p->random) p->next->random = p->random->next;

		H h{0};
		for (auto p = head, q = &h; p != nullptr; p = p->next) {
			q->next = p->next;
			q = q->next;
			p->next = q->next;
		}
		return h.next;
	}
};
