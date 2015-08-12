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
	ListNode* partition(ListNode* head, int x) {
		ListNode l{0}, r{0}, *s = &l, *t = &r;
		for (; head != nullptr; head = head->next) {
			if (head->val < x) {
				s->next = head;
				s = head;
			} else {
				t->next = head;
				t = head;
			}
		}
		s->next = r.next;
		t->next = nullptr;
		return l.next;
	}
};
