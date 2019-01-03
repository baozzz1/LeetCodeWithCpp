// Easy, Medium or Hard
// Medium
#include"ListNode.h"
#include"TreeNode.h"
#include"Interval.h"

// Runtime: 44 ms, faster than 54.27% of C++ online submissions for Add Two Numbers.
// 可改进的点：可while(l1&&l2),while(l1), while(l2)来节省判断次数
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *res = new ListNode(NULL);
		ListNode *p = res;
		int sum;
		int tenth = 0;
		while (l1 != NULL || l2 != NULL) {
			sum = ((l1 != NULL) ? l1->val : 0) + ((l2 != NULL) ? l2->val : 0) + tenth;
			p->next = new ListNode(sum % 10);
			tenth = sum / 10;
			p = p->next;
			l1 = l1 ? l1->next : l1;
			l2 = l2 ? l2->next : l2;
		}
		if (tenth) p->next = new ListNode(tenth);
		return res->next;
	}
};