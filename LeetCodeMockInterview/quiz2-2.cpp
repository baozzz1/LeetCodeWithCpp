// Easy, Medium or Hard
// 
#include"ListNode.h"
#include"TreeNode.h"
#include"Interval.h"

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;
		int num;
		ListNode* pre = new ListNode(-1);
		ListNode* curr = pre;
		while (l1 && l2) {
			num = l1->val + l2->val + carry;
			if (num > 9) {
				num -= 10;
				carry = 1;
			}
			else
				carry = 0;
			curr->next = new ListNode(num);
			curr = curr->next;
			l1 = l1->next; l2 = l2->next;
		}
		while (l1) {
			num = l1->val + carry;
			if (num > 9) {
				num -= 10;
				carry = 1;
			}
			else
				carry = 0;
			curr->next = new ListNode(num);
			curr = curr->next;
			l1 = l1->next;
		}
		while (l2) {
			num = l2->val + carry;
			if (num > 9) {
				num -= 10;
				carry = 1;
			}
			else
				carry = 0;
			curr->next = new ListNode(num);
			curr = curr->next;
			l2 = l2->next;
		}
		if (carry)
			curr->next = new ListNode(carry);
		return pre->next;
	}
};

int main() {
	Solution slu;
		ListNode* l1 = new ListNode(2);
	ListNode* l2 = new ListNode(4);
	ListNode* l3 = new ListNode(3);
	l1->next = l2; l2->next = l3;

	ListNode* s1 = new ListNode(5);
	ListNode* s2 = new ListNode(6);
	ListNode* s3 = new ListNode(4);
	s1->next = s2; s2->next = s3;
	ListNode* res = slu.addTwoNumbers(l1, s1);

}