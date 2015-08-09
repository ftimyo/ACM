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
	ListNode* reverseList(ListNode* head) {
		ListNode t(0), *x = nullptr;
		for (; head != nullptr;) {
			x = head;
			head = head->next;
			x->next = t.next;
			t.next = x;
		}
		return t.next;
	}
};
