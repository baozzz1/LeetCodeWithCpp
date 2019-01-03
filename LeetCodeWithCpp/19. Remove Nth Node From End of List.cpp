// Easy, Medium or Hard
// 
#include"ListNode.h"
#include"TreeNode.h"
#include"Interval.h"

// Runtime: 4 ms, faster than 33.56% of C++ online submissions for Sort Colors.
// 可改进的点：
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int length = 0;
		ListNode *p = head;
		while (p) {
			p = p->next;
			length++;
		}
		length = n - length;

		p = head->next;
		ListNode *first = head;
		while (length--) {
			first = first->next;
			p = p->next;
		}
		first->next = first->next->next;
		return head;
	}
};