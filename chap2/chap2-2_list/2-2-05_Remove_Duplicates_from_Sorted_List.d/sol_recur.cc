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
		auto p = head, q = p->next;
		while (q && q->val == p->val) {
			auto d = q;
			q = q->next;
			delete d;
		}
		p->next = deleteDuplicates(q);
		return p;
	}
};
