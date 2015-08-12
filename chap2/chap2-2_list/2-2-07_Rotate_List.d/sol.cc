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
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head || !head->next) return head;
		int l = 1; auto t = head;
		for (; t->next; t = t->next) ++l;
		t->next = head; k = l - k % l;
		for (int i = 0; i < k; ++i) t = t->next;
		head = t->next; t->next = nullptr;
		return head;
	}
};
