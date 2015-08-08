/**
 * Definition for singly-linked list.
 * struct ListNode {
 *	 int val;
 *	 ListNode *next;
 *	 ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#ifndef LOCAL
struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(nullptr) {}
};
#endif

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode head(0), *t = &head;
		int c = 0; /*carry*/
		auto tail = [&t, &c](ListNode *h) {
			for (; h != nullptr; h = h->next, t = t->next) {
				auto sum = h->val + c;
				t->next = new ListNode(sum % 10);
				c = sum / 10;
			}
		};
		for (; l1 != nullptr && l2 != nullptr; l1 = l1->next, l2 = l2->next, t = t->next) {
			auto sum = l1->val + l2->val + c;
			t->next = new ListNode(sum % 10);
			c = sum / 10;
		}
		tail(l1);
		tail(l2);
		if (c) t->next = new ListNode(c);
		return head.next;
	}
};
