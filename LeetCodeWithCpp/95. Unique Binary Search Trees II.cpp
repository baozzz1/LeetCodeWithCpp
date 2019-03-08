// Easy, Medium or Hard
// 
#include"ListNode.h"
#include"TreeNode.h"
#include"Interval.h"

// Runtime: 4 ms, faster than 33.56% of C++ online submissions for Sort Colors.
// 可改进的点：
class Solution {
public:
	void insert(TreeNode* &root, const int &num) {
		if (!root)
			root = new TreeNode(num);
		else if (num < root->val)
			insert(root->left, num);
		else
			insert(root->right, num);
	}
};

//
//
//int main() {
//	Solution slu;
//	TreeNode* l1 = new TreeNode(1);
//	TreeNode* l2 = new TreeNode(4);
//	TreeNode* l3 = new TreeNode(5);
//	slu.insert(l1, 2);
//
//	return 0;
//}