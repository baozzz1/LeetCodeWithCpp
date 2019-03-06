// Easy, Medium or Hard
// Medium
#include"ListNode.h"
#include"TreeNode.h"
#include"Interval.h"
#include<stack>

// Runtime: 4 ms, faster than 33.56% of C++ online submissions for Sort Colors.
// 可改进的点：
class Solution {
public:
	/*vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		inorderRecursive(root, res);
		return res;
	}

	void inorderRecursive(TreeNode* node, vector<int> &res) {
		if (!node)	return;
		inorderRecursive(node->left,res);
		res.push_back(node->val);
		inorderRecursive(node->right,res);
	}*/

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> s;
		TreeNode *node = root;
		while (s.size() != 0 || node) {
			if (node) {
				s.push(node);
				node = node->left;
			}
			else {
				node = s.top();
				s.pop();
				res.push_back(node->val);
				node = node->right;
			}
		}
	}
};