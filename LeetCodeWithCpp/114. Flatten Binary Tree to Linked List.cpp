#include"TreeNode.h"

// Hard Question
class Solution {
public:
	void flatten(TreeNode* root) {
		TreeNode *curr = root;
		TreeNode *target = root;
		onePath(curr, target);

	}

	void onePath(TreeNode* curr, TreeNode* target) {
		if (!curr) return;
		target = new TreeNode(curr->val);
		target = target->left;
		onePath(curr->left, target);
		onePath(curr->right, target);
	}
};