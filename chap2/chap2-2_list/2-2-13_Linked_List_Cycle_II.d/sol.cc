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
	ListNode *detectCycle(ListNode *head) {
		for (auto p = head, q = p; q && q->next;) {
			p = p->next; q = q->next->next;
			if (p == q) {
				for (auto r = head; r != q; r = r->next, q = q->next);
				return q;
			}
		}
		return nullptr;
	}
};
