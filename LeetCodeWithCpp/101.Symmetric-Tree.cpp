#include"TreeNode.h"

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (!root)
			return true;
		return isMirror(root->left, root->right);
	}

	bool isMirror(TreeNode* left, TreeNode* right) {
		if (!left && !right)
			return true;
		else if (!left || !right)
			return false;
		if (left->val == right->val)
			return isMirror(left->left, right->right) && isMirror(left->right, right->left);
		return false;
	}
};