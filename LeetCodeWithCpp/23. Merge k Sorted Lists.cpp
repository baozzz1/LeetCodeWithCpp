// Easy, Medium or Hard
// Hard
#include"ListNode.h"
#include"TreeNode.h"
#include"Interval.h"

class Solution {
public:
	struct cmp {
		bool operator()(ListNode* &l1, ListNode* &l2) {
			return l1->val > l2->val;
		}
	};
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
		for (int i = 0; i < lists.size(); i++) {
			if (lists[i])
				heap.push(lists[i]);
		}
		if (heap.size() == 0) return NULL;
		ListNode root(-1);
		ListNode* temp = NULL;
		ListNode* ptr = &root;
		while (heap.size()) {
			temp = heap.top();
			heap.pop();
			ptr->next = temp;
			ptr = ptr->next;
			if (temp->next)
				heap.push(temp->next);
		}
		return root.next;
	}
};
//
//
//int main() {
//	Solution slu;
//	ListNode* l1 = new ListNode(1);
//	ListNode* l2 = new ListNode(4);
//	ListNode* l3 = new ListNode(5);
//	l1->next = l2; l2->next = l3;
//
//	ListNode* s1 = new ListNode(1);
//	ListNode* s2 = new ListNode(3);
//	ListNode* s3 = new ListNode(4);
//	s1->next = s2; s2->next = s3;
//
//	ListNode* t1 = new ListNode(2);
//	ListNode* t2 = new ListNode(6);
//	t1->next = t2;
//
//	vector<ListNode*> input = { l1,s1,t1 };
//	slu.mergeKLists(input);
//
//	return 0;
//}