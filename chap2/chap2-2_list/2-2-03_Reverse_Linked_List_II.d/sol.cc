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
  ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode b{0}; b.next = head; int i = 0; auto c = &b;
		while (i < m - 1) {c = c->next; ++i;}
		auto pm = c; c = c->next; ListNode tm{0}, *x;
		for (i = m; i <= n; ++i) {
			x = c; c = c->next;
			x->next = tm.next;
			tm.next = x;
		}
		pm->next->next = c;
		pm->next = tm.next;
		return b.next;
	}
};
