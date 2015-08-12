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
		if (p->val == q->val) {
			while (q && q->val == p->val) q = q->next;
			while (p != q) {auto d = p; p = p->next; delete d;}
			return deleteDuplicates(q);
		}
		p->next = deleteDuplicates(q);
		return p;
	}
};
