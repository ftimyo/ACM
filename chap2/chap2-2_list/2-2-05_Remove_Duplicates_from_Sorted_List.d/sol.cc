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
		if (head == nullptr) return nullptr;
		auto p = head, q = head->next;
		for (; q != nullptr; q = q->next) {
			if (p->val != q->val) {p = q; continue;}
			p->next = q->next;
			delete q;
			q = p;
		}
		return head;
	}
};
